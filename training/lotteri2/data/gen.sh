#!/bin/bash
. ../../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution joshua.cpp

compile gen_rand.py

samplegroup
sample_manual 1
sample_manual 2
sample_manual 3

group g1 100
include_group sample
for i in {1..20}; do
    tc g1-$i gen_rand n=$i
done
for i in {21..30}; do
    tc g1-$i gen_rand n=20
done
