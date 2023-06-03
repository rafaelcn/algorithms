#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <string>

/**
 * @brief Interface defined as a base of all sort algorithms
 */
class Algorithm {
public:
    Algorithm(std::string alg_name) : name(alg_name) {}
    virtual ~Algorithm() {}

    /// The name of the algorithm
    std::string name;

    /**
     * @brief Function that sorts data
     */
    virtual std::vector<int> sort(std::vector<int>) = 0;
};

#endif // ALGORITHMS_H
