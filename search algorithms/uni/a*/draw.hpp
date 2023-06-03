#ifndef DRAW_H
#define DRAW_H

#include "graph.hpp"

void draw_graph(const Graph& graph,
               const int field_width,
               Node *const agent = nullptr,
               std::map<Node, double>* distances = nullptr,
               std::map<Node, Node>* point_to = nullptr,
                std::vector<Node>* path = nullptr);

#endif // DRAW_H
