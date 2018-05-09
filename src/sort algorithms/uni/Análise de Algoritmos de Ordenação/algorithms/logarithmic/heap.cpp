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

#include "heap.h"


void Heap::heapify(std::vector<int> &v, int n, int i) {

    int largest = i;

    // position of the sons of the node at v[i]
    int l = 2*i+1;
    int r = 2*(i+1);

    if (l < n && v[l] > v[largest]) {
        largest = l;
    }

    if (r < n && v[r] > v[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void Heap::heap(std::vector<int> &v, int n) {

    // build heap
    for (int i = n/2-1; i >= 0; i--) {
        heapify(v, n, i);
    }

    // sort
    for (int i = n - 1; i >= 0; i--) {
        std::swap(v[0], v[i]);
        // update the heap every time you change the original instance
        heapify(v, i, 0);
    }
}

std::vector<int> Heap::sort(std::vector<int> instance) {

    heap(instance, instance.size());

    return instance;
}
