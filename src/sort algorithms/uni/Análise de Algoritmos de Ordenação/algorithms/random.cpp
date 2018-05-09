#include "./random.hpp"

// Forward declaration of a static member
std::random_device Random::m_random_device;

int Random::get(int a, int b) {

    std::mt19937 generator(m_random_device());
    std::uniform_int_distribution<> distribution(a, b);

    return distribution(generator);
}
