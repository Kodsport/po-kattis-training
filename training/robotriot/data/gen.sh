#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution solution.cpp

compile gen.py

samplegroup
sample 1
sample 2
sample 3

group g1 63
include_group sample
tc_manual ../manual_data/04.in
tc_manual ../manual_data/05.in
tc_manual ../manual_data/06.in
tc_manual ../manual_data/07.in
tc_manual ../manual_data/08.in

group g2 37
include_group g1
tc_manual ../manual_data/09.in
tc_manual ../manual_data/10.in
tc_manual ../manual_data/11.in
tc_manual ../manual_data/12.in
