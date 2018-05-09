#ifndef MERGE_H
#define MERGE_H

#include <vector>
#include <cstdlib>

template<typename T>
void merge_s(std::vector<T> &, std::size_t, std::size_t, std::size_t);

template <typename T>
void merge(std::vector<T> &v, std::size_t l, std::size_t r) {

    if (l < r) {
        std::size_t p = (l+r) >> 1;

        merge(v, l, p);
        merge(v, p+1, r);
        merge_s(v, l, p, r);
    }
}

template <typename T>
void merge_s(std::vector<T> &v, std::size_t l, std::size_t p, std::size_t r) {

    // I will have to reuse variables from the function signature, so I will
    // save them in other variables

    std::size_t lbegin = l;
    std::size_t rbegin = p+1;
    std::size_t end = r;

    std::size_t size = r-l+1;

    int *aux = (int*) calloc(size, sizeof(int));
    std::size_t aux_i = 0;

    // comparing piece of the algorithm

    while (lbegin <= p && rbegin <= r) {
        if (v[lbegin] < v[rbegin]) {
            aux[aux_i] = v[lbegin];
            lbegin++;
        } else {
            aux[aux_i] = v[rbegin];
            rbegin++;
        }

        aux_i++;
    }

    while (lbegin <= p) {
        aux[aux_i] = v[lbegin];
        lbegin++;
        aux_i++;
    }

    while (rbegin <= r) {
        aux[aux_i] = v[rbegin];
        rbegin++;
        aux_i++;
    }

    // Last but not least you have to fill back the vector passed as a
    // parameter

    for (aux_i = l; aux_i <= r; aux_i++) {
        v[aux_i] = aux[aux_i-l];
    }

    free(aux);
}

#endif // MERGE_H
