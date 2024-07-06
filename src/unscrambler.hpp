#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <algorithm>
#include <iostream>

#include "trie.hpp"

class Unscrambler {
public:
    Unscrambler();

    std::vector<std::string> unscramble(std::string& letters);
    bool search(const std::string& word) const;
private:
    void load_dictionary(const std::string& path);

    Trie dictionary;
};