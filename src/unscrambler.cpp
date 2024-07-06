#include "unscrambler.hpp"

Unscrambler::Unscrambler() {
    dictionary = Trie();
    load_dictionary("./dict");
    std::cout << "Loaded dictionary" << std::endl;
}

bool Unscrambler::search(const std::string& word) const {
    std::string upper = word;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    return dictionary.search(upper);
}

void Unscrambler::load_dictionary(const std::string& path) {
    std::ifstream dict(path);

    if (!dict.is_open()) {
        std::cerr << "Could not open the dictionary." << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(dict, line)) {
        dictionary.insert(line);
    }
}