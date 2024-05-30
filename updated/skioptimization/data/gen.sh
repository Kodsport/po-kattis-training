#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution ski_js.cpp


samplegroup
limits maxn=150 maxk=10
sample sample1
sample sample2



group subtask1 19
limits maxn=150 maxk=10
include_group sample
tc_manual ../manual_data/link.01.in
tc_manual ../manual_data/link.02.in


group subtask2 24
limits maxn=5000 maxk=20
include_group subtask1
tc_manual ../manual_data/link.03.in
tc_manual ../manual_data/link.04.in
tc_manual ../manual_data/link.05.in

group subtask3 37
limits maxn=100000 maxk=20000
include_group subtask2
tc_manual ../manual_data/link.06.in
tc_manual ../manual_data/link.07.in
tc_manual ../manual_data/link.08.in
tc_manual ../manual_data/link.09.in
tc_manual ../manual_data/link.10.in

group subtask4 20
limits maxn=500000 maxk=20000
include_group subtask3
tc_manual ../manual_data/link.11.in
tc_manual ../manual_data/link.12.in
tc_manual ../manual_data/link.13.in
tc_manual ../manual_data/link.14.in
tc_manual ../manual_data/link.15.in
tc_manual ../manual_data/link.16.in
tc_manual ../manual_data/link.17.in
tc_manual ../manual_data/link.18.in
tc_manual ../manual_data/link.19.in
tc_manual ../manual_data/link.20.in
tc_manual ../manual_data/link.21.in
tc_manual ../manual_data/link.22.in
tc_manual ../manual_data/link.23.in
tc_manual ../manual_data/link.24.in
tc_manual ../manual_data/link.25.in
