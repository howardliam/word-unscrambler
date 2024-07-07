# Word Unscrambler
This program finds all possible word matches in an (scrambled) input string.
The dictionary is stored in a Trie and words are 'unscrambled' using a pruning tree search.

## Limitations
- Dictionaries must be line delimited
- Only supports ASCII A-Z (other language support is out of the scope of this project)

## Requirements
- Meson
- A C++ compiler that supports C++20

## Installation
For Linux:
```bash
$ meson setup builddir && cd builddir
$ meson compile
$ cp ../dict .
$ ./word-unscrambler
```

## Todo
- [x] Trie dictionary
- [x] Unscrambler
- [x] No uppercase requirement for Trie