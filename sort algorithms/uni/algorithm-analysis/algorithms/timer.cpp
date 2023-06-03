#include "timer.hpp"
#include "vector_utils.hpp"

time_duration time_it(Algorithm *algorithm, std::vector<int> instance) {

    auto t0 = Timer::now();
    std::vector<int> sorted = algorithm->sort(instance);
    auto t1 = Timer::now();

    if (sorted.size() < 20) {
        std::cout << " ";
        print_vector(sorted);
    }

    time_duration time = t1-t0;

    return time;
}

ms to_milliseconds (time_duration time) {
    return std::chrono::duration_cast<ms>(time);
}

sec to_seconds(time_duration time) {
    return std::chrono::duration_cast<sec>(time);
}
