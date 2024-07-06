#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <signal.h>

#include "trie.hpp"
#include "unscrambler.hpp"
#include "utils.hpp"

void handler(int s) {
    std::cout << "\n\nExiting..." << std::endl;
    exit(0);
}

int main(int argc, char** argv) {
    struct sigaction sig_int_handler;
    sig_int_handler.sa_handler = handler;
    sigaction(SIGINT, &sig_int_handler, NULL);

    Unscrambler unscrambler;

    std::string input;

    while (true) {
        std::cout << "Type some scrambled text [ctrl+C to exit]: ";
        std::cin >> input;

        auto res = unscrambler.unscramble(input);
        printing::sorted_print(res);

        if (res.empty()) {
            std::cout << "No results." << std::endl;
        }
    }
}
