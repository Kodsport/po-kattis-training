#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution fullsatt_js.cpp

samplegroup
sample sample1
sample sample2
sample sample3

group g1 100
include_group sample
tc_manual ../manual_data/fullsatt01.in
tc_manual ../manual_data/fullsatt02.in
tc_manual ../manual_data/fullsatt03.in
tc_manual ../manual_data/fullsatt04.in
tc_manual ../manual_data/fullsatt05.in
tc_manual ../manual_data/fullsatt06.in
tc_manual ../manual_data/fullsatt07.in
tc_manual ../manual_data/fullsatt08.in
tc_manual ../manual_data/fullsatt09.in
