#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution reverse_js.cc

samplegroup
sample sample1
sample sample2

group g1 100
include_group sample
tc_manual reverse1
tc_manual reverse2
tc_manual reverse3
tc_manual reverse4
