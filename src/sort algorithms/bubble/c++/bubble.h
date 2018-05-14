#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>
#include <cstdio>

template <typename T>
void bubble_sort(std::vector<T> &instance) {

    for (std::size_t i = 0; i < instance.size(); i++) {
        bool swapped = true;

        for (std::size_t j = 1; j < instance.size() && swapped; j++) {
            swapped = false;

            if (instance[j] < instance[j-1]) {
                std::swap(instance[j], instance[j-1]);
                swapped = true;
            }
        }
    }
}

#endif // BUBBLE_H
