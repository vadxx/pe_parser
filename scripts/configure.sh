#!/bin/bash
mkdir -p build release &&
cd ../build &&
rm -rf * && 
cmake -DCMAKE_BUILD_TYPE=Debug ..