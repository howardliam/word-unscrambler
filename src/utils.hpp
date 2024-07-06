#pragma once

#include <string>
#include <algorithm>

inline std::string to_upper(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}