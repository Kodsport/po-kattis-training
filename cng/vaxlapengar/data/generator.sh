#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution joshua.cpp

compile print.py

samplegroup
sample 1
sample 2

group group1 100
include_group sample
tc g1-1 print n=1
tc g1-2 print n=16
tc g1-3 print n=99
tc g1-4 print n=96
tc g1-5 print n=95
tc g1-6 print n=81
tc g1-7 print n=52
tc g1-8 print n=19
tc g1-9 print n=20
tc g1-10 print n=21
tc g1-11 print n=22
tc g1-12 print n=23
tc g1-13 print n=24
tc g1-14 print n=25
