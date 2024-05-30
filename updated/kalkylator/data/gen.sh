#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution kalkylator_js.cpp

samplegroup
sample sample1
sample sample2
sample sample3
sample sample4
sample sample5

group g1 100
include_group sample
tc_manual kalkylator01
tc_manual kalkylator02
tc_manual kalkylator03
