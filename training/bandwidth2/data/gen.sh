#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution bandwidth_js.cpp

compile gen.py

samplegroup
sample sample01
sample sample02
sample sample03
sample sample04

group g1 23
include_group sample
tc g1-1 gen random 8 10
tc g1-2 gen near 8 10
tc g1-3 gen spanning 8 10
tc g1-4 gen random 8 28
tc g1-5 gen near 8 28
tc g1-6 gen spanning 8 28


group g2 30
include_group g1
tc g2-1 gen random 1000 3000
tc g2-2 gen random 1000 5000
tc g2-3 gen near 1000 5000
tc g2-4 gen spanning 1000 5000
tc g2-5 gen random 100 4950
tc g2-6 gen near 100 4950
tc g2-7 gen spanning 100 4950

group g3 47
include_group g2
tc g3-1 gen random 700 244650
tc g3-2 gen near 700 244650
tc g3-3 gen spanning 700 244650
tc g3-4 gen random 100000 300000
tc g3-5 gen near 100000 300000
tc g3-6 gen spanning 100000 300000

