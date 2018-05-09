/** MIT License
 *
 * Copyright (c) 2017-2018 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "merge.h"

void Merge::merge(std::vector<int> &v, std::size_t l, std::size_t r) {

    if (l < r) {
        std::size_t p = (l+r) >> 1;

        merge(v, l, p);
        merge(v, p+1, r);
        merge_partition(v, l, p, r);
    }
}

void Merge::merge_partition(std::vector<int> &v, std::size_t l, std::size_t p,
                            std::size_t r) {

    // I will have to reuse variables from the function signature, so I will
    // save them in other variables

    std::size_t lbegin = l;
    std::size_t rbegin = p+1;
    //std::size_t end = r;

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

std::vector<int> Merge::sort(std::vector<int> instance) {

    merge(instance, 0, instance.size()-1);
    return instance;
}
