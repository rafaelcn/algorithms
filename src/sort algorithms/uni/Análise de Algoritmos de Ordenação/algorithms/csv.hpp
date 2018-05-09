#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <fstream>
#include <iostream>
#include <utility>

int write_csv(std::string &, std::pair<int, double>);
int write_csv(std::string &, std::vector<std::pair<int, double>>);

#endif // UTILS_H
