#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution joshua.py

compile print.py

samplegroup
sample 1
sample 2
sample 3
sample 4

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
