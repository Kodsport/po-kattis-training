#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution threesort_js.cc

samplegroup
sample sample1
sample sample2
sample sample3

group g1 100
include_group sample
tc_manual 1
tc_manual 2
tc_manual 3
tc_manual 4
