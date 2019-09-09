/*
    Copyright 2019.
*/
#pragma once
#include "base/reader.h"

class PE_Reader : public Reader {
 protected:
    size_t pe_offset;
    size_t sect_hdr_offset;
    WORD num_of_sects;
    
 public:
     PE_Reader();
    ~PE_Reader();

    size_t get_sz_opt_header();
    BOOL read_file_header();  // calcs sect_hdr_offset

    BOOL read_signature();
    BOOL read_sections();
    BOOL read_import_table();
    BOOL read_export_table();
};
