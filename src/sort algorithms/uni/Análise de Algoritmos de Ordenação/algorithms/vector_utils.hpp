#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include <vector>
#include <iostream>

void print_vector(std::vector<int> &v) {

    for (auto &e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

#endif // VECTOR_UTILS_H
