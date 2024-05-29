#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution joshua.cpp

compile print.py

samplegroup
sample 1

group group1 100
include_group sample
tc g1-1 print
tc g1-2 print
tc g1-3 print
tc g1-4 print
tc g1-5 print
tc g1-6 print
tc g1-7 print
tc g1-8 print
tc g1-9 print
