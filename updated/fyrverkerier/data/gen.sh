#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution simon.cc

compile rand_ratio.py
compile rand.py

samplegroup
sample sample01
sample sample02
sample sample03

group g1 100
include_group sample
tc g1-1 rand_ratio
tc g1-2 rand_ratio
tc g1-3 rand_ratio
tc g1-4 rand_ratio
tc g1-5 rand_ratio
tc g1-6 rand_ratio
tc g1-7 rand_ratio
tc g1-8 rand_ratio
tc g1-9 rand
tc g1-10 rand
tc g1-11 rand
tc g1-12 rand
tc g1-13 rand
tc g1-14 rand
