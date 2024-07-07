#pragma once

#include <string>
#include <vector>
#include <memory>

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct TrieNode {
    char value;
    bool is_word;
    std::vector<std::shared_ptr<TrieNode>> children;

    TrieNode(char val = '\0');
    ~TrieNode();
};

class Trie {
public:
    Trie();
    ~Trie();

    void insert(const std::string& word);
    bool search(const std::string& word) const;

    std::shared_ptr<TrieNode> get_root();

private:
    std::shared_ptr<TrieNode> root;
};