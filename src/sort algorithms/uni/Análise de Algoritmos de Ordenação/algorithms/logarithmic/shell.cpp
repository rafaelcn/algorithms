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

#include "shell.h"

std::vector<int> Shell::sort(std::vector<int> instance)  {

    unsigned int gap = 1;
    unsigned int i, j;

    while (gap < instance.size()) {
        gap = gap*3+1;
    }

    while (gap > 1) {
        gap /= 3;

        for (i = gap; i < instance.size(); i++) {
            int aux = instance[i];
            j = i;

            while (j >= gap && aux < instance[j-gap]) {
                instance[j] = instance[j-gap];
                j -= gap;
            }

            instance[j] = aux;
        }
    }

    return instance;
}
