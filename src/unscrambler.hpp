#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <algorithm>
#include <iostream>
#include <set>

#include "utils.hpp"

#include "trie.hpp"

class Unscrambler {
public:
    Unscrambler();

    std::set<std::string> unscramble(std::string& letters);
    bool search(const std::string& word) const;
private:
    void load_dictionary(const std::string& path);
    // void brute_unscramble(std::string word, std::string letters);
    void recursive_unscramble(const std::shared_ptr<TrieNode>& current_node, std::string building, std::string letters);

    Trie dictionary;
    std::set<std::string> matches;
};