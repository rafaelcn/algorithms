#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <thread>
#include <chrono>

#include "pqueue.hpp"
#include "colors.hpp"

struct Node {
    int x, y;

    bool operator==(const Node& rhs) {
        return this->x == rhs.x && this->y == rhs.y;
    }

    bool operator!=(const Node &rhs) {
        return !(*this == rhs);
    }
};

inline bool operator<(const Node& lhs, const Node &rhs)  {
    return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
}

inline std::basic_iostream<char>::basic_ostream& operator<<(
    std::basic_iostream<char>::basic_ostream& out,
    const Node& loc) {
    out << '(' << loc.x << ',' << loc.y << ')';
    return out;
}

struct Graph {
    static std::array<Node, 4> DIRS;

    int width, height;
    std::set<Node> walls;

    // Kinds of existent tiles
    std::set<Node> rocky;
    std::set<Node> sand;
    std::set<Node> mug;
    std::set<Node> reward;

    Graph(int w, int h): width(w), height(h) {}

    bool in_bounds(Node node) const;
    bool passable(Node node) const;

    std::vector<Node> neighbors(Node node) const;

    double cost(Node from_node, Node to_node) const;

    void add_wall(int x1, int y1, int x2, int y2);
};

Graph create_graph();

inline double heuristic(Node a, Node b) {
    return std::sqrt((std::abs(a.x - b.x)^2) + (std::abs(a.y - b.y)^2));
}

void a_star_search(Graph graph, Node start, Node goal,
                   std::map<Node, Node>& came_from,
                   std::map<Node, double>& cost_so_far);


void breadth_first_search(Graph graph, Node start, Node goal,
                          std::map<Node, Node> &came_from);

std::vector<Node> reconstruct_path(const Node start, const Node goal,
                                   std::map<Node, Node> came_from);

#endif // GRAPH_H
