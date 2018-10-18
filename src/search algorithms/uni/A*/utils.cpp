#include "utils.hpp"

#include <cstdlib>

void clear() {
#ifdef __unix__
    system("clear");
#elif
    system("cls");
#endif //
}
