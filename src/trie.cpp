#include "trie.hpp"

TrieNode::TrieNode(char val) {
    value = val;
    is_word = false;
    children.reserve(26);
    for (int i = 0; i < 26; i++) {
        children.emplace_back(nullptr);
    }
}

TrieNode::~TrieNode() = default;

Trie::Trie() {
    root = std::make_shared<TrieNode>();
}

Trie::~Trie() = default;

void Trie::insert(const std::string& word) {
    std::shared_ptr<TrieNode> current = root;
    for (char ch : word) {
        int index = ch - 'A';
        if (!current->children[index]) {
            current->children[index] = std::make_shared<TrieNode>(ch);
        }
        current = current->children[index];
    }
    current->is_word = true;
}

bool Trie::search(const std::string& word) const {
    std::shared_ptr<TrieNode> current = root;
    for (char ch : word) {
        int index = ch - 'A';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current->is_word;
}
