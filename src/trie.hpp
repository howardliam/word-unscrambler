#pragma once

#include <string>
#include <vector>
#include <memory>

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

private:
    std::shared_ptr<TrieNode> root;
};