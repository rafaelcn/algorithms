#include "quick.h"

void Quick::quick(std::vector<int> &v, int l, int r) {

    std::pair<int, int> p = partition(v, l, r);

    if (l < p.second) {
        quick(v, l, p.second);
    }

    if (p.first < r) {
        quick(v, p.first, r);
    }
}

std::pair<int, int> Quick::partition(std::vector<int> &v, int l,
                                           int r) {

    std::pair<int, int> pair;

    pair.first = l;
    pair.second = r;

    int pivot = v[(pair.first+pair.second) >> 1];

    do {
        while (v[pair.first] < pivot) pair.first++;
        while (v[pair.second] > pivot) pair.second--;

        if (pair.first <= pair.second) {
            std::swap(v[pair.first], v[pair.second]);
            pair.first++;
            pair.second--;
        }

    } while (pair.first <= pair.second);

    return pair;
}

std::vector<int> Quick::sort(std::vector<int> instance) {

    quick(instance, 0, instance.size()-1);

    return instance;
}
