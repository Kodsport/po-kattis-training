#!/bin/bash
g++ gen.cpp

./a.out <<< "1 1" > secret/fullsatt01.in
./a.out <<< "2 1" > secret/fullsatt02.in
./a.out <<< "1 2" > secret/fullsatt03.in
./a.out <<< "1 10" > secret/fullsatt04.in
./a.out <<< "2 10" > secret/fullsatt05.in
./a.out <<< "20 30" > secret/fullsatt06.in
./a.out <<< "50 30" > secret/fullsatt07.in
./a.out <<< "75 50" > secret/fullsatt08.in
./a.out <<< "100 50" > secret/fullsatt09.in

g++ ../submissions/accepted/fullsatt_js.cpp

for x in secret/*.in;
do
	./a.out < secret/fullsatt01.in > secret/fullsatt01.ans
	./a.out < secret/fullsatt02.in > secret/fullsatt02.ans
	./a.out < secret/fullsatt03.in > secret/fullsatt03.ans
	./a.out < secret/fullsatt04.in > secret/fullsatt04.ans
	./a.out < secret/fullsatt05.in > secret/fullsatt05.ans
	./a.out < secret/fullsatt06.in > secret/fullsatt06.ans
	./a.out < secret/fullsatt07.in > secret/fullsatt07.ans
	./a.out < secret/fullsatt08.in > secret/fullsatt08.ans
	./a.out < secret/fullsatt09.in > secret/fullsatt09.ans
done
