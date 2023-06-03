#ifndef COLORS_H
#define COLORS_H

#include <string>

#if defined __linux__ && HAS_COLORS
const std::string red       = "\033[0;31m";
const std::string bold_red  = "\033[1;31m";
const std::string yellow    = "\033[0;33m";
const std::string white     = "\033[0;37m";
const std::string blue      =  "\033[0;34m";
const std::string green     = "\033[0;32m";
const std::string brown     = "\033[48;5;16m";
const std::string rocky     = "\033[48;5;239m";
const std::string black     = "\033[48;5;232m";
const std::string reset     = "\033[0m";
#else
const std::string red      = "";
const std::string bold_red = "";
const std::string yellow   = "";
const std::string white    = "";
const std::string blue     = "";
const std::string green    = "";
const std::string brown    = "";
const std::string rocky    = "";
const std::string black    = "";
const std::string reset    = "";
#endif // __linux__

#endif // COLORS_H
