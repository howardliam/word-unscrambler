#pragma once

#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>

inline std::string to_upper(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

inline std::string to_lower(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

namespace printing {
    constexpr int MAX_WIDTH = 50;

    std::map<int, std::set<std::string>> sort_words_by_length(std::set<std::string> words);
    std::vector<int> word_lengths_descending(const std::map<int, std::set<std::string>>& sorted_words);
    void sorted_print(std::set<std::string> words);
}
