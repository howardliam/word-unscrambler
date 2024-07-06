cmake_minimum_required(VERSION 3.28.0)

project(
    word-unscrambler 
    VERSION 0.1.0 
    LANGUAGES CXX
)

add_executable(
    word-unscrambler 
    src/main.cpp 
    src/trie.cpp 
    src/trie.hpp
    src/unscrambler.cpp
    src/unscrambler.hpp
    src/utils.cpp
    src/utils.hpp
)
