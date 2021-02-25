#include "draw.hpp"

void draw_graph(const Graph& graph, const int field_width, Node *const agent,
                std::map<Node, double>* distances,
                std::map<Node, Node>* point_to,
                std::vector<Node>* path) {

    for (int y = 0; y != graph.height; ++y) {
        for (int x = 0; x != graph.width; ++x) {
            Node id {x, y};

            //std::this_thread::sleep_for(std::chrono::milliseconds(5));

            std::cout << std::left << std::setw(field_width);

            if (agent && *agent == id) {
                std::cout << std::setw(field_width+1) << "☺" << std::flush;
            }

            if (graph.walls.find(id) != graph.walls.end()) {
                std::cout << std::setw(0);
                for (int i = 0; i < field_width; i++) {
                    std::cout << "▓";
                }
                std::cout << std::setw(field_width);
            }  else if (point_to != nullptr &&
                        point_to->count(id) &&
                        *agent != id) {

                Node next = (*point_to)[id];

                if (next.x == x + 1) {
                    std::cout << "> ";
                } else if (next.x == x - 1) {
                    std::cout << "< " << std::flush;
                } else if (next.y == y + 1) {
                    std::cout << "v " << std::flush;
                } else if (next.y == y - 1) {
                    std::cout << "^ " << std::flush;
                }
            } else if (distances != nullptr && distances->count(id)) {
                std::cout << (*distances)[id];
            } else if (path && find(path->begin(), path->end(), id) !=
                   path->end()) {
                std::cout << std::setw(field_width) << "☺ " << std::flush;
            } else {
                if (graph.mug.find(id) != graph.mug.end()) {
                    std::cout << "M" << std::flush;
                } else if (graph.rocky.find(id) != graph.rocky.end()) {
                    std::cout << "R" << std::flush;
                } else if (graph.sand.find(id) != graph.sand.end()) {
                    std::cout << "S" << std::flush;
                } else if (graph.reward.find(id) != graph.reward.end()) {
                    std::cout << "$" << std::flush;
                } else {
                // Plain terrain
                    std::cout << " " << std::flush;
                }
            }
        }

        std::cout << std::endl;
    }
}
