# Word Unscrambler
This program finds all possible word matches in an (scrambled) input string.
The dictionary is stored in a Trie and words are 'unscrambled' using a pruning tree search.

## Limitations
- Dictionaries must be line delimited
- Only supports ASCII A-Z (other language support is out of the scope of this project)

## Requirements
- CMake
- A C++ compiler

## Todo
- [x] Trie dictionary
- [x] Unscrambler
- [x] No uppercase requirement for Trie