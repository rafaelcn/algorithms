#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdint>

#include "random.hpp"
#include "csv.hpp"
#include "timer.hpp"
#include "methods.hpp"

#include "quadratic/quadratic.hpp"
#include "logarithmic/logarithmic.hpp"


void fill(std::vector<int> &, size_t, FillMethod);

int main(int argc, char **argv) {

    // Total value stored in RAM will be approximately of 1,2MiB (?)
    std::vector<int> random_values;
    std::vector<int> crescent_values;
    std::vector<int> decrescent_values;

    const int upper_bound = 10E5;

    random_values.resize(upper_bound);
    crescent_values.resize(upper_bound);
    decrescent_values.resize(upper_bound);

    // values at which the algorithm will test.
    const std::vector<int> stops = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                                    200, 300, 400, 500, 600, 700, 800, 900,
                                    1000, 2000, 3000, 4000, 5000, 6000, 7000,
                                    8000, 9000, 10000, 20000, 30000, 40000,
                                    50000, 60000, 70000, 80000, 90000,
                                    upper_bound};

    std::vector<FillMethod> methods = {RANDOM, CRESCENT, DECRESCENT};

    std::vector<Algorithm *> algorithms = {new Bubble("bubble"),
                                           new Selection("selection"),
                                           new Insertion("insertion"),
                                           new Shell("shell"),
                                           new Quick("quick"),
                                           new Heap("heap"),
                                           new Merge("merge")};

    const uint8_t test_times = 10;

    fill(random_values, upper_bound, RANDOM);
    fill(crescent_values, upper_bound, CRESCENT);
    fill(decrescent_values, upper_bound, DECRESCENT);

    for (auto algorithm : algorithms) {
        for (auto stop_point : stops) {
            for (auto method : methods) {
                std::cout << "STARTING TEST " << method << ":"
                          << algorithm->name << " | "
                          << "DATA STOP: " << stop_point << "\n";

                ms time_avg = ms(0);
                // time data to be written in a .csv
                std::pair<int, double> data;
                // name of the .csv file
                std::string filename = "./csv_files/" + algorithm->name;

                for (uint8_t i = 0; i < test_times; i++) {
                    std::vector<int> partition;
                    partition.resize(stop_point);

                    switch (method) {
                    case RANDOM:
                        for (int j = 0; j < stop_point; j++) {
                            partition[j] = random_values[j];
                        }

                        filename += i == 0 ? "-random" : "";
                        break;
                    case CRESCENT:
                        for (int j = 0; j < stop_point; j++) {
                            partition[j] = crescent_values[j];
                        }

                        filename += i == 0 ? "-crescent" : "";
                        break;
                    case DECRESCENT:
                        for (int j = 0; j < stop_point; j++) {
                            partition[j] = decrescent_values[j];
                        }

                        filename += i == 0 ? "-decrescent" : "";
                        break;
                    }

                    time_duration time_taken = time_it(algorithm, partition);
                    ms in_ms = to_milliseconds(time_taken);

                    std::cout << "\nTime taken: " << in_ms.count() << "ms";

                    time_avg += in_ms;
                }

                std::cout << "\nAverage time: " << time_avg.count()/10.0
                          << "ms\n";

                data.first = stop_point;
                data.second = time_avg.count()/10.0;
                filename += ".csv";

                write_csv(filename, data);
            }
        }
    }

    return 0;
}

void fill(std::vector<int> &v, size_t size, FillMethod method) {

    switch (method) {
    case RANDOM:
        for (size_t i = 0; i < size; i++) {
            v[i] = Random::get(1, 100000);
        }
        break;
    case CRESCENT:
        for (size_t i = 0; i < size; i++) {
            v[i] = i;
        }
        break;
    case DECRESCENT: {
        int i = 0;
        for (int j = size; j > 0; j--) {
            v[i] = j;
            ++i;
        }
        break;
    }
    }
}
