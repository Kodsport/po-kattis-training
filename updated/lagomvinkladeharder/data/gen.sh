#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution sl_opt.cpp

compile gen.py

samplegroup
sample sample1
sample sample2

group g1 100
include_group sample
tc g1-1 gen
tc g1-2 gen
tc g1-3 gen
tc g1-4 gen
tc g1-5 gen
tc g1-6 gen
