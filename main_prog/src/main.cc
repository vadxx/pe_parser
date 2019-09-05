/*
    Copyright 2019.
*/
#include <iostream>
#include "../pe_reader/src/pe_reader.h"

int main(int argc, char const *argv[]) {
    PE_Reader reader;

    if (argc > 1) {
        std::cout << argv[1] << std::endl;
        reader.init(argv[1]);
    } else {
        std::cerr << "No file name entered. Exiting..." << std::endl;
        return -1;
    }
    return 0;
}
