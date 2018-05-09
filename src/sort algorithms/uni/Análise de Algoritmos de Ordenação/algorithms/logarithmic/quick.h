#ifndef QUICK_H
#define QUICK_H

#include <vector>
#include <algorithm>

#include "../algorithms.hpp"

class Quick : public Algorithm {
public:
    Quick(std::string alg_name) : Algorithm(alg_name) {}
    ~Quick() {}

    std::vector<int> sort(std::vector<int>) override;
private:
    std::pair<int, int> partition(std::vector<int> &, int, int);
    void quick(std::vector<int> &, int, int);
};

#endif // QUICK_H
