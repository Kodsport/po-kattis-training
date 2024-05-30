#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution ../dummy.cpp

group g1 100
tc_manual katalog1