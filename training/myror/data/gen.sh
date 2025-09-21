#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution myror.py

compile gen.py

samplegroup
sample sample1
sample sample2
sample sample3
sample sample4

group g1 100
include_group sample
tc_manual secret1
tc_manual secret2
tc_manual secret3
tc_manual secret4
tc_manual secret5

