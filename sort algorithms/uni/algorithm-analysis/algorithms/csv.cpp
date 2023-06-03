#include "csv.hpp"

// file.csv
// data_stops, time
// 10, ...
// 20, ...
// ..., ...
// 100000, ...

int write_csv(std::string &filename, std::pair<int, double> data) {

    std::fstream f;
    const char *filename_c = filename.c_str();

    f.open(filename_c, f.in);

    if (!f.is_open()) {
        // file probably doesn't exist (other errors might occur, I'm ignoring)
        f.close();
        f.open(filename_c, f.out | f.app);
        f << "data,time\n";
    }

    f.close();
    f.open(filename_c, f.out | f.app);
    f << data.first << "," << data.second << "\n";

    return 0;
}

int write_csv(std::string &filename,
              std::vector<std::pair<int, double>> data) {

    for (auto e : data) {
        write_csv(filename, e);
    }

    return 0;
}
