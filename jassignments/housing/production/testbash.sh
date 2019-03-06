#!/bin/bash

make clean
make
./$1 >|testOut.txt
less testOut.txt
