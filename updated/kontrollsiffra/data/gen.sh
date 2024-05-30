#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution js.cc

samplegroup
sample sample01


group g1 100
include_group sample
tc_manual test01
tc_manual test02
tc_manual test03
tc_manual test04
tc_manual test05
