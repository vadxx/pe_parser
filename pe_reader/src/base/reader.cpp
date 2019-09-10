/*
    Copyright 2019.
*/
#include "base/reader.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;

Reader::Reader() : buff(std::make_shared<string>()) {}
Reader::~Reader() { file.close(); }

BOOL Reader::init(const string& fp) {
    file.open(fp, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        cout << "ERROR can't open file!" << endl;
        return false;
    }
    get_len_file();
    return true;
}

BOOL Reader::test() {
    cout << "Oops! Empty!" << endl;
    return false;
}

BOOL Reader::get_header(
    const size_t& offset, const size_t& size,
    const BOOL& printable) {
    buff->resize(size);
    file.seekg(offset, file.beg);
    file.read(const_cast<char*>(buff->c_str()), buff->length());
    if (!file) {
        cout << "Unable to read header: " << buff << endl;
        return false;
    }
    if (printable) {
        cout << "'" << *buff << "' ";
    }
    return true;
}

DWORD Reader::get_len_file() {
    file.seekg(0, file.end);
    DWORD length = file.tellg();
    file.seekg(0, file.beg);
    cout << "File len: " << length << endl;
    return length;
}

size_t Reader::get_data() {
    return *buff->data();
}
