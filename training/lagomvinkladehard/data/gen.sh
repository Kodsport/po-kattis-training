#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution sol2.cpp


samplegroup
sample sample1
sample sample2

group g1 100
include_group sample
tc_manual secret1
tc_manual secret2
tc_manual secret3
