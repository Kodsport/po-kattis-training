#!/bin/bash
. ../../../testdata_tools/gen.sh

use_solution joshua.py

compile gen_rand.py

samplegroup
sample sample1
sample sample2
sample sample3

group g1 100
include_group sample
tg_manual ../manual_tests
for i in {1..12}; do
    tc g1-$i gen_rand
done
