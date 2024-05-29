#!/bin/bash

set -e

# arguments
testcase  () {
    (( TC += 1 ))
    echo $GENERATOR $CURGROUP$TC $1
    TCNAME=$PROBLEMNAME.$CURGROUPNAME.`printf "%02d" $TC`
    ${GENERATOR} $CURGROUP$TC $1 > secret/$CURGROUPNAME/$TCNAME.in
    echo "testcase $TCNAME 1" >> spec
}

SOLVER=sol
SUB=()
CURGROUP=0
# group, score
group () {
    TC=0
    (( CURGROUP += 1 ))
    CURGROUPNAME=$1
    group_hook $CURGROUP $2
    SUB[$CURGROUP]=secret/$1
    echo ${SUB[$CURGROUP]}
    if [ ! -d secret/$1 ]
    then
        mkdir secret/$1
    fi
    echo "grading: custom
grader_flags: all $2" > secret/$1/testdata.yaml
    echo "Generating group $1"
}

initialize () {
    g++ ../submissions/accepted/$SOLUTION -std=c++11 -o $SOLVER
    rm -rf secret
    mkdir -p secret

}

# group, score
group_hook (){
    echo "GROUP $2 Subtask $1" >> spec
}

testcase_hook() {
    cp $1.in all
    cp $1.ans all
}

end_hook () {
    return
    zip all.zip all
}

generate_solutions () {
    # generate solutions for all files
    if [[ ! -z $SOLVER ]]
    then
        for i in `seq 1 $CURGROUP`
        do
            for f in ${SUB[$i]}/*.in
            do
                echo "solving $f"
                ./$SOLVER < $f > ${f%???}.ans
                testcase_hook ${f%???}
            done
        done
    fi
}

# Set the problem name to generate correct file names
PROBLEMNAME="bandwidth"

# Set the name of an AC solution
SOLUTION="bandwidth_js.cpp"

# The testdata generator
GENERATOR="python3 gen.py"

initialize

group g1 23
testcase "random 8 10"
testcase "near 8 10"
testcase "spanning 8 10"
testcase "random 8 28"
testcase "near 8 28"
testcase "spanning 8 28"


group g2 30
testcase "random 1000 3000"
testcase "random 1000 5000"
testcase "near 1000 5000"
testcase "spanning 1000 5000"
testcase "random 100 4950"
testcase "near 100 4950"
testcase "spanning 100 4950"

group g3 47
testcase "random 700 244650"
testcase "near 700 244650"
testcase "spanning 700 244650"
testcase "random 100000 300000"
testcase "near 100000 300000"
testcase "spanning 100000 300000"


generate_solutions
end_hook
