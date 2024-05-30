#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution caesar_js.cc

compile gen.py

samplegroup
sample sample1
sample sample2

group g1 100
include_group sample
tc_manual caesar1
tc_manual caesar2
tc_manual caesar3
