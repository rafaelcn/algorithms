#include <iostream>
#include <vector>

#include "quick.h"

int main() {

    std::vector<int> instance;
    instance.resize(1000);

    int j = instance.size();

    for (int i = 0; i < instance.size(); i++) {
        instance[i] = j;
        j--;
    }

    std::cout << "Unsorted instance: ";

    for (auto e : instance) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    quick(instance);

    std::cout << "Sorted instance:   ";

    for (auto e : instance) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    return 0;
}
