/*
    Copyright 2019.
    Orig info: https://habr.com/ru/post/266831/
*/
#include "src/pe_reader.h"
#include <iostream>

using std::cout;
using std::endl;
using std::hex;

struct Data_Dir {
    DWORD VirtAddr;
    DWORD Size;
};

const int sz_File_Header = 20;
const int NUM_DIR_ENTRIES = 16;
const int SZ_OF_SHORT_NAMES = 8;

PE_Reader::PE_Reader() : Reader() {}
PE_Reader::~PE_Reader() {}

BOOL PE_Reader::test() {
    read_signature();
    read_file_header();
    read_sections();
    get_sections();
    return true;
}

BOOL PE_Reader::read_signature() {
    auto offset = 0x3c;  // e_lfnew
    get_header(offset, sizeof(DWORD));
    pe_offset = static_cast<BYTE>(*buff->data());
    cout << "PE Offset: " << hex << pe_offset << " ";
    get_header(pe_offset, sizeof(DWORD), true);  // PE
    cout << endl;
    return true;
}

BOOL PE_Reader::read_sections() {
    auto offset = sect_hdr_offset;
    vpSects.resize(num_of_sects);
    // parse sections
    for (size_t i = 0; i < num_of_sects; i++) {
        get_header(offset, sizeof(BYTE) * SZ_OF_SHORT_NAMES);
        // fill structure
        Section sect;
        sect.id = i;
        sect.name = *buff;
        sect.offset = offset;
        // send to vec
        // auto pSect = std::make_shared<Section>(sect);
        vpSects.at(i) = sect;
        // go next
        offset += 0x28;
    }
    return true;
}

BOOL PE_Reader::get_sections() {
    cout << "Sections: " << endl;
    cout << "ID  Name\tOffset" << endl;
    for (auto &&i : vpSects) {
        cout << i.id << "  " << i.name << "\t";
        cout << hex << i.offset << endl;

        // if (i.id == 3) {  // OK
        if (i.name.compare(".idata") == 0) {  // Not OK (
            cout << "HELLO!" << endl;
        }
    }
    return true;
}

BOOL PE_Reader::read_import_table() {
    cout << "HELLO" << endl;
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
