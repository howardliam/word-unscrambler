#include "unscrambler.hpp"

Unscrambler::Unscrambler() {
    dictionary = Trie();
    load_dictionary("./dict");
    std::cout << "Loaded dictionary" << std::endl;

    matches = std::set<std::string>();
}

std::set<std::string> Unscrambler::unscramble(std::string& letters) {
    matches.clear();

    recursive_unscramble(dictionary.get_root(), "", to_upper(letters));

    return matches;
}

bool Unscrambler::search(const std::string& word) const {
    return dictionary.search(to_upper(word));
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

// void Unscrambler::brute_unscramble(std::string word, std::string letters) {
//     if (dictionary.search(word)) {
//         matches.insert(word);
//     }

//     for (int i = 0; i < letters.size(); i++) {
//         auto new_letters = letters;
//         new_letters.erase(i, 1);

//         char current_letter = letters[i];
//         brute_unscramble(word + current_letter, new_letters);
//     }
// }

void Unscrambler::recursive_unscramble(const std::shared_ptr<TrieNode>& current_node, std::string building, std::string letters) {
    if (current_node->is_word) {
        matches.insert(building);
    }

    for (int i = 0; i < letters.size(); i++) {
        char letter = letters[i];

        int index = letter - 'A';
        std::shared_ptr<TrieNode> next_node = current_node->children[index];
        if (!next_node) continue;

        auto new_building = building + letter;
        auto new_letters = letters;
        new_letters.erase(i, 1);

        recursive_unscramble(next_node, new_building, new_letters);
    }
}
