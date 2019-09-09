/*
    Copyright 2019.
*/
#pragma once
#include <memory>
#include <string>
#include <vector>

typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef uint8_t BOOL;

typedef std::shared_ptr<uint32_t> ptDWORD;
typedef std::shared_ptr<uint16_t> ptWORD;
typedef std::shared_ptr<uint8_t> ptBYTE;
typedef std::shared_ptr<uint8_t> ptBOOL;

typedef std::shared_ptr<std::string> ptStr;

// typedef std::vector<BYTE> vByte;
// typedef std::shared_ptr<vByte> pvByte;

// typedef std::vector<char> vChar;
// typedef std::shared_ptr<std::vector<char>> pvChar;



