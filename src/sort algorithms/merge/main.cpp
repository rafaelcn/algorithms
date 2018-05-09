#include <iostream>
#include <vector>

#include "merge.h"

int main() {

    std::vector<int> instance = {9, 3, 1, 4, 5, 10, 2, 8, 6, 7};

    std::cout << "Unsorted instance: ";

    for (auto e : instance) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    merge(instance, 0, instance.size()-1);

    std::cout << "Sorted instance:   ";

    for (auto e : instance) {
        std::cout << e << " ";
    }
    std::cout << "\n";


    return 0;
}
