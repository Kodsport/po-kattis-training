#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution simon.cpp

compile gen.py

samplegroup
sample sample01
sample sample02
sample sample03
sample sample04

group g1 100
include_group sample
tc g1-1 gen
tc g1-2 gen
tc g1-3 gen
tc g1-4 gen
tc g1-5 gen
