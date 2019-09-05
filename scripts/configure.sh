#!/bin/bash
mkdir -p build released_bins &&
cd ./build &&
rm -rf * && 
cmake -DCMAKE_BUILD_TYPE=RelWithDebug --clean-first ..