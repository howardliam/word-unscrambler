#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "trie.hpp"
#include "unscrambler.hpp"

int main(int argc, char** argv) {
    Unscrambler unscrambler;

    std::string word = "unscramble";

    if (argc > 1) {
        word = argv[1];
    }

    if (unscrambler.search(word)) {
        std::cout << word + " found in trie" << std::endl;
    } else {
        std::cout << word + " not found in trie" << std::endl;
    }
}
