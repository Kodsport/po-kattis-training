#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution triangel.cc

compile gen.py

samplegroup
sample sample1
sample sample2
sample sample3
sample sample4

maxN=1000000
group g1 100
include_group sample
tc g1-1 gen -$maxN
tc g1-2 gen -$maxN
tc g1-3 gen -$maxN
tc g1-4 gen -$maxN
tc g1-5 gen $maxN 1
tc g1-6 gen $maxN 0
tc g1-7 gen $maxN -1

