/*
    Copyright 2019.
*/
#include <iostream>
#include "../pe_reader/src/pe_reader.h"

using std::cout;
using std::endl;
using std::cerr;

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        cerr << "ERROR No file name entered! Exiting..." << endl;
        cout << "USAGE: main_prog 'path/to/file'" << endl;
        return -1;
    } else {
        cout << "File path: " << argv[1] << ", ";
        PE_Reader rdr;
        if (!rdr.init(argv[1])) {
            cout << "ERROR Init! Exiting..." << endl;
            return -1;
        } else {
            rdr.test();
            cout << endl << "OK!" << endl;
        }
    }
    return 0;
}
