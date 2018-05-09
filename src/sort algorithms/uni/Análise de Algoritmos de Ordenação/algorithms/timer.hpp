#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <vector>

#include "algorithms.hpp"

// Useful typedefs

typedef std::chrono::high_resolution_clock Timer;
typedef std::chrono::milliseconds ms;
typedef std::chrono::seconds sec;
typedef std::chrono::duration<double> time_duration;

time_duration time_it(Algorithm *algorithm, std::vector<int>);

sec  to_seconds(time_duration);
ms   to_milliseconds(time_duration);

#endif // TIMER_H
