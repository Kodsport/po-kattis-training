#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution bijektion_js.cpp


samplegroup
sample sample1
sample sample2
sample sample3
sample sample4

group g1 100
include_group sample
tc_manual ../manual_data/bijektion01.in
tc_manual ../manual_data/bijektion02.in
tc_manual ../manual_data/bijektion03.in
tc_manual ../manual_data/bijektion04.in
tc_manual ../manual_data/bijektion05.in
tc_manual ../manual_data/bijektion06.in
tc_manual ../manual_data/bijektion07.in
tc_manual ../manual_data/bijektion08.in
tc_manual ../manual_data/bijektion09.in
tc_manual ../manual_data/bijektion10.in
