#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>

template <typename T>
void bubble_sort(std::vector<T> &instance) {

    for (std::size_t i = 0; i < instance.size(); i++) {
        for (std::size_t j = 1; j < instance.size(); j++) {
            if (instance[j] < instance[j-1]) {
                std::swap(instance[j], instance[j-1]);
            }
        }
    }
}

#endif // BUBBLE_H
