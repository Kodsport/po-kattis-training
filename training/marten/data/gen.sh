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
PROBLEMNAME="marten"

# Set the name of an AC solution
SOLUTION="marten_js.cpp"

# The testdata generator
GENERATOR="python3 gen.py"

initialize

group g1 19
testcase "complete,valid 8"
testcase "complete,valid 8"
testcase "random,valid 8 16"
testcase "random,valid 8 20"
testcase "star,valid 8"
testcase "random,early 8 16"
testcase "random,invalid1 8 20"
testcase "random,invalid1 8 20"
testcase "random,invalid1 8 20"

group g2 43
testcase "complete,valid 100"
testcase "complete,valid 100"
testcase "random,valid 1000 2000"
testcase "random,valid 1000 5000"
testcase "star,valid 1000"
testcase "random,early 1000 1100"
testcase "random,invalid1 1000 2000"
testcase "random,invalid1 1000 5000"
testcase "random,early 1000 5000"
testcase "random,invalid2 1000 5000"

group g3 38
testcase "complete,valid 750"
testcase "complete,valid 750"
testcase "random,valid 100000 200000"
testcase "random,valid 100000 300000"
testcase "star,valid 100000"
testcase "random,early 100000 200000"
testcase "random,early 100000 300000"
testcase "random,invalid1 100000 300000"
testcase "random,invalid2 100000 300000"
testcase "star,invalid1 100000"

generate_solutions
end_hook
