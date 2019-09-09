/*
    Copyright 2019.
*/
#pragma once
#include <cstdint>
#include <fstream>  // for file-access
#include <string>
#include "src/types.h"

class Reader {
 protected:
    std::ifstream file;
    ptStr buff;
    size_t offset;

    BOOL get_header(
        const size_t& offset = 0, const size_t& size = 0,
        const BOOL& printable = false);

    DWORD get_len_file();

    size_t get_data();

 public:
     Reader();
    ~Reader();

    virtual BOOL init(const std::string& fp);
};
