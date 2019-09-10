/*
    Copyright 2019.
*/
#pragma once
#include <string>
#include <vector>
#include "base/reader.h"

using std::string;

struct Section {
    uint id = 0;
    std::string name = "";
    uint offset = 0;
};
typedef std::vector<Section> pvSect;

class PE_Reader : public Reader {
 protected:
    size_t pe_offset = 0;
    size_t sect_hdr_offset = 0;
    WORD num_of_sects = 0;
    pvSect vpSects;

    size_t get_sz_opt_header();
    BOOL read_file_header();  // calcs sect_hdr_offset

    BOOL read_signature();
    BOOL read_sections();
    BOOL get_sections();

    BOOL read_import_table();
    BOOL read_export_table();

 public:
    PE_Reader();
    ~PE_Reader();
    BOOL test();
};
