/*
    Copyright 2019.
    Orig info: https://habr.com/ru/post/266831/
*/
#include "src/pe_reader.h"
#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::hex;
using std::string;
using std::map;

const int sz_File_Header = 20;

struct Data_Dir {
    DWORD VirtAddr;
    DWORD Size;
};
const int NUM_DIR_ENTRIES = 16;
const int SZ_OF_SHORT_NAMES = 8;

PE_Reader::PE_Reader()
  : Reader(),
    pe_offset(0) {}
PE_Reader::~PE_Reader() {}

BOOL PE_Reader::read_signature() {
    auto offset = 0x3c;  // e_lfnew
    get_header(offset, sizeof(DWORD));
    pe_offset = get_data();  // 0x78
    cout << "PE Offset: " << hex << pe_offset << " ";
    get_header(pe_offset, sizeof(DWORD), true);  // PE
    cout << endl;
    return true;
}

BOOL PE_Reader::read_sections() {
    auto offset = sect_hdr_offset;
    cout << "Sections: ";

    std::map <size_t, string> sects;
    for (size_t i = 0; i < num_of_sects; i++) {
        get_header(offset, sizeof(BYTE) * SZ_OF_SHORT_NAMES);
        sects[i] = *buff;
        offset += 0x28;
    }  // .text .rdata .data .00cfg .gfids .rsrc .reloc etc
    for (auto&& i : sects) {
        cout << ' ' << i.second;
    }

    return true;
}

BOOL PE_Reader::read_import_table() {
    return false;
}

BOOL PE_Reader::read_export_table() {
    return false;
}

BOOL PE_Reader::read_file_header() {
    auto offset = pe_offset;
    // Signature + Machine
    offset += sizeof(DWORD) + sizeof(WORD);
    // NUM OF SECTS
    get_header(offset, sizeof(num_of_sects));
    num_of_sects = get_data();
    cout << "Num of sects: " << hex << num_of_sects << endl;
    offset += sizeof(num_of_sects);
    // TimeDateStamp + PointerToSymbolTable + NumberOfSymbols
    offset += sizeof(DWORD) * 3;
    // SizeOfOptionalHeader + Characteristics;
    offset += sizeof(WORD) * 2;

    sect_hdr_offset = offset + get_sz_opt_header();
    return true;
}

size_t PE_Reader::get_sz_opt_header() {
    auto sz_opt_header = sizeof(WORD) + sizeof(BYTE) * 2;
    sz_opt_header += sizeof(DWORD) * 9;
    sz_opt_header += sizeof(WORD) * 6 + sizeof(DWORD) * 4;
    sz_opt_header += sizeof(WORD) * 2 + sizeof(DWORD) * 6;
    sz_opt_header += sizeof(Data_Dir) * NUM_DIR_ENTRIES;
    return sz_opt_header;
}
