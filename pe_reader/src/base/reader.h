/*
    Copyright 2019.
*/
#pragma once
#include <cstdint>
#include <string>
#include <fstream>  // for file-access

typedef uint32_t DWORD;
typedef uint32_t UINT;
typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef uint8_t BOOL;

class Reader {
 protected:
    std::ifstream file;

    BOOL read_file(const std::string& fp);
    std::string read_line();

 public:
    Reader(/* args */);
    ~Reader();

    BOOL init(const std::string& fp);
};
