#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua.cpp

compile gen_rand.py


sample 1

tc g1_1 gen_rand n=10
tc g1_2 gen_rand n=100
tc g1_3 gen_rand n=1000
tc g1_4 gen_rand n=10000
