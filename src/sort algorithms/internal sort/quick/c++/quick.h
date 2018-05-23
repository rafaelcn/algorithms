#ifndef QUICK_H
#define QUICK_H

#include <vector>
#include <algorithm>

template <typename T>
std::pair<T, T> partition(std::vector<T> &, T, T);

template <typename T>
void sort(std::vector<T> &v, T l, T r) {

    std::pair<T, T> p = partition(v, l, r);

    if (l < p.second) {
        sort(v, l, p.second);
    }

    if (p.first < r) {
        sort(v, p.first, r);
    }
}

template <typename T>
std::pair<T, T> partition(std::vector<T> &v, T l, T r) {

    std::pair<T, T> pair;

    pair.first = l;
    pair.second = r;

    size_t pivot = v[(pair.first+pair.second) >> 1];

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
template <typename T>
void quick(std::vector<T> &v) {
    sort(v, 0, (int)v.size()-1);
}

#endif // QUICK_H
