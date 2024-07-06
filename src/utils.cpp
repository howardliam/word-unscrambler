#include "utils.hpp"

std::map<int, std::set<std::string>> printing::sort_words_by_length(std::set<std::string> words) {
    std::map<int, std::set<std::string>> sorted;

    for (auto word : words) {
        int length = word.size();
        sorted[length].insert(word);
    }

    return sorted;
}

std::vector<int> printing::word_lengths_descending(const std::map<int, std::set<std::string>> &sorted_words) {
    std::vector<int> word_lengths;

    for (auto& entry : sorted_words) {
        word_lengths.push_back(entry.first);
    }

    std::reverse(word_lengths.begin(), word_lengths.end());

    return word_lengths;
}

void printing::sorted_print(std::set<std::string> words) {
    std::cout << std::endl;
    
    auto sorted_words = sort_words_by_length(words);
    auto word_lengths = word_lengths_descending(sorted_words);

    for (int length : word_lengths) {
        auto words = sorted_words[length];
        for (auto word : words) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
