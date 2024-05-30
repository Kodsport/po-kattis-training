#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution johan.cpp

compile rand.py

samplegroup
sample sample01
sample sample02
sample sample03
sample sample04

group g1 20
include_group sample
tc g1-1 rand 1000
tc g1-2 rand 1000
tc g1-3 rand 1000
tc g1-4 rand 1000
tc g1-5 rand 1000
tc g1-6 rand 1000
tc g1-7 rand 1000

group g2 80
include_group g1
tc g2-1 rand -1
tc g2-2 rand -1
tc g2-3 rand -1
tc g2-4 rand -1
tc g2-5 rand -1
tc g2-6 rand -1
tc g2-7 rand -1
