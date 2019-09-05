/*
    Copyright 2019.
*/
#include "base/reader.h"
#include <iostream>

Reader::Reader() {}

Reader::~Reader() {}

BOOL Reader::init(const std::string& fp) {
    if (read_file(fp)) {
        read_line();
        return true;
    }
    return false;
}

BOOL Reader::read_file(const std::string& fp) {
    // test
    file.open(fp);
    if (file.is_open() && file.good()) {
        return true;
    }
    return false;
}

std::string Reader::read_line() {
    std::string line = "";
    getline(file, line);
    std::cout << "Text:\n" << std::hex << line << std::endl;
    return line;
}


