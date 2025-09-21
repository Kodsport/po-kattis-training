#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution triangel3.cc

compile gen.py

samplegroup
sample sample1
sample sample2
sample sample3
sample sample4
sample sample5

group g1 20
include_group sample
tc_manual ../manual_data/secret01.in
tc_manual ../manual_data/secret02.in
tc_manual ../manual_data/secret03.in
tc_manual ../manual_data/secret04.in
tc_manual ../manual_data/secret05.in

group g2 35
include_group g1
tc_manual ../manual_data/secret11.in
tc_manual ../manual_data/secret12.in
tc_manual ../manual_data/secret13.in
tc_manual ../manual_data/secret14.in
tc_manual ../manual_data/secret15.in

group g3 45
include_group g2
tc_manual ../manual_data/secret21.in
tc_manual ../manual_data/secret22.in
tc_manual ../manual_data/secret23.in
tc_manual ../manual_data/secret24.in
tc_manual ../manual_data/secret25.in
