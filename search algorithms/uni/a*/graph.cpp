#include "graph.hpp"
#include "random.hpp"

static Node east{1, 0};
static Node south{0, -1};
static Node west{-1, 0};
static Node north{0, 1};

std::array<Node, 4> Graph::DIRS {east, south, west, north};

bool Graph::in_bounds(Node node) const {

    bool x_bound = 0 <= node.x && node.x < width;
    bool y_bound = 0 <= node.y && node.y < height;

    return x_bound && y_bound; //&& walls.find(node) == walls.end();
}

bool Graph::passable(Node node) const {

    return walls.find(node) == walls.end();
}

std::vector<Node> Graph::neighbors(Node node) const {

    std::vector<Node> results;

    for (Node dir : DIRS) {
        Node next{node.x + dir.x, node.y + dir.y};
        if (in_bounds(next) && passable(next)) {
            results.push_back(next);
        }
    }

    if ((node.x + node.y) % 2 == 0) {
        std::reverse(results.begin(), results.end());
    }

    return results;
}

double Graph::cost(Node from_node, Node to_node) const {

    double cost = 4;

    if (rocky.find(to_node) != rocky.end()) {
        cost = 8;
    } else if (sand.find(to_node) != sand.end()) {
        cost = 11;
    } else if (mug.find(to_node) != mug.end()) {
        cost = 15;
    } else if (reward.find(to_node) != reward.end()) {
        cost = 0;
    }

    return cost;
}

void Graph::add_wall(int x1, int y1, int x2, int y2) {
  for (int x = x1; x < x2; ++x) {
    for (int y = y1; y < y2; ++y) {
      walls.insert(Node{x, y});
    }
  }
}

Graph create_graph() {

    // The graph represented as a grid
    Graph grid(25, 20);

    // Adding bound walls
    grid.add_wall(0, 0, 1, grid.height);
    grid.add_wall(grid.width-1, 0, grid.width, grid.height);
    grid.add_wall(0, 0, grid.width, 1);
    grid.add_wall(0, grid.height-1, grid.width, grid.height);

    // TODO: Randomize more the generation of walls
    for (int i = 1; i <= 100; i++) {
        int x  = 0;
        int y  = 0;

        x = Random::get(3, grid.width);
        y = Random::get(3, grid.height);

        grid.walls.insert(Node{x, y});
        grid.walls.insert(Node{x, y+1});
    }

    grid.rocky = std::set<Node> {};
    grid.sand = std::set<Node> {};
    grid.mug = std::set<Node> {};
    grid.reward = std::set<Node> {};

    for (int x = 0; x < grid.width; x++) {
        for (int y = 0; y < grid.height; y++) {
            int choice = Random::get(0, 30);

            if (choice < 10) {
                grid.rocky.insert(Node{x,y});
                grid.sand.insert(Node{x, y});
            } else if (choice >= 15 && choice <= 17) {
                grid.sand.insert(Node{x, y});
            } else if (choice > 20 && choice <= 23) {
                grid.mug.insert(Node{x, y});
            } else if (choice > 23 && choice <= 26) {
                grid.reward.insert(Node{x, y});
            }
        }
    }

    return grid;
}

void a_star_search(Graph graph,
                   Node start,
                   Node goal,
                   std::map<Node, Node>& came_from,
                   std::map<Node, double>& cost_so_far) {

    PriorityQueue<Node, double> frontier;
    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        auto current = frontier.get();

        if (current == goal) {
            break;
        }

        for (Node next : graph.neighbors(current)) {
            double new_cost = cost_so_far[current] +
                graph.cost(current, next);

            bool c = cost_so_far.find(next) == cost_so_far.end();
            bool n = new_cost < cost_so_far[next];

            if (c || n) {
                cost_so_far[next] = new_cost;
                double priority = new_cost + heuristic(next, goal);
                frontier.put(next, priority);
                came_from[next] = current;
            }
        }
    }
}

void breadth_first_search(Graph graph, Node start, Node goal,
                          std::map<Node, Node> &came_from) {

    std::queue<Node> frontier;

    frontier.push(start);
    came_from[start] = start;

    while (!frontier.empty()) {
        Node current = frontier.front();
        frontier.pop();

        if (current == goal) {
            break;
        }

        for (Node neighbor : graph.neighbors(current)) {
            auto is_contained = came_from.find(neighbor);

              if (is_contained == came_from.end()) {
                frontier.push(neighbor);
                came_from[current] = neighbor;
              }
        }
    }
}

std::vector<Node> reconstruct_path(const Node start, const Node goal,
                                    std::map<Node, Node> came_from) {
    std::vector<Node> path;
    Node current = goal;

    // Verifies before hand if the goal node is contained in came_from
    // in other words: does the algorithm found the goal?
    auto is_contained = came_from.find(goal);

    if (is_contained != came_from.end()) {
        while (current != start) {
            path.push_back(current);
            current = came_from[current];
        }

        path.push_back(start);
    } else {
        path = std::vector<Node>();
    }

    std::reverse(path.begin(), path.end());

    return path;
}
