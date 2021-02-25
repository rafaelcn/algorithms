#include <iostream>
#include <vector>
#include <map>

// Change the following definition to 1 if you want to see colors.
#define HAS_COLORS 0

#include "graph.hpp"
#include "draw.hpp"
#include "utils.hpp"
#include "colors.hpp"

void print_path_taken(std::vector<Node>,
                      std::map<Node, double>);

int main(int argc, char **argv) {

    std::cout << "\nThis is a randomly generated map\n\n"
              << "LEGEND:\n"
              << ". -> Plain terrain\tcost:  1\n"
              << "R -> Rocky terrain\tcost: 10\n"
              << "M -> Mug terrain\tcost: 20\n"
              << "S -> Sand terrain\tcost: 4\n"
              << "$ -> Reward terrain\tcost: 0\n"
              << "▓ -> Walls\n"
              << red << "X -> Goal\n\n" << reset;

    // Creating and drawing the grid map
    Graph grid = create_graph();

    Node start{2, 2};
    Node goal;

    draw_graph(grid, 4, &start);

    std::vector<std::map<Node, Node>> came_from;
    std::vector<std::map<Node, double>> cost_so_far;

    came_from.push_back(std::map<Node, Node>());
    came_from.push_back(std::map<Node, Node>());

    cost_so_far.push_back(std::map<Node, double>());
    cost_so_far.push_back(std::map<Node, double>());

    int x;
    int y;

    std::cout << "\nSet the X coordinate: ";
    std::cin >> x;

    std::cout << "Set the Y coordinate: ";
    std::cin >> y;

    goal.x = x;
    goal.y = y;

    a_star_search(grid, start, goal, came_from[0], cost_so_far[0]);
    breadth_first_search(grid, start, goal, came_from[1]);

    bool run = true;

    while (run) {

        std::cout << "\nWhich of the algorithms would you like to see the output?"
                  << "\n1 -> A*"
                  << "\n2 -> BFS"
                  << "\n3 -> Exit"
                  << "\n: ";

        int decision = 0;
        std::cin >> decision;

        switch(decision) {
        case 1: {
            clear();
            draw_graph(grid, 4, &start, nullptr, &(came_from[0]));

            std::cout << "\nThe cost of each step of the path searched\n\n";

            draw_graph(grid, 4, nullptr, &(cost_so_far[0]), nullptr);

            std::cout << "\nThe path taken by the algorithm\n\n";

            std::vector<Node> path = reconstruct_path(start, goal,
                                                      came_from[0]);
            if (path.size() == 0) {
                std::cout << bold_red
                          << "The path couldn't be found for the current goal."
                          << reset << std::endl;
            } else {
                draw_graph(grid, 4, nullptr, nullptr, nullptr, &path);
                print_path_taken(path, cost_so_far[0]);
            }
            break;
        }
        case 2: {
            clear();
            draw_graph(grid, 4, &start, nullptr, &(came_from[1]));

            std::cout << "\nThe path taken by the algorithm\n\n";

            std::vector<Node> path = reconstruct_path(start, goal, came_from[1]);

            if (path.size() == 0) {
                std::cout << bold_red
                          << "The path couldn't be found for the current goal."
                          << reset << std::endl;
            } else {
                draw_graph(grid, 4, nullptr, nullptr, nullptr, &path);
            }
            break;
        }
        case 3:
            run = false;
        default:
            break;
        }
    }

    std::cout << "\n--------- Final report:"
              << "\n\nA* node usage: " << came_from[0].size()
              << "\nBFS node usage: " << came_from[1].size()
              << "\n\n";

    return 0;
}

void print_path_taken(std::vector<Node> path,
                      std::map<Node, double> cost_so_far) {
    char op;

    std::cout << "\n\nWish to see the path taken by the algorithm (y/n): ";
    std::cin >> op;

    if (op == 'y') {
        std::cout << "Coordinate -> Cost" << std::endl;
        for (const auto location : path) {
            auto cost = cost_so_far.find(location);
            if (cost != cost_so_far.end()) {
                std::cout << cost->first <<  " -> " << cost->second
                          << std::endl;
            }
        }
    }
}
