g++ -o gen gen.cpp

./gen 10 0 42341 > secret/heap01.in
./gen 10 1 43262 > secret/heap02.in
./gen 10 2 764713 > secret/heap03.in
./gen 1000 0 235464 > secret/heap04.in
./gen 1000 1 54265 > secret/heap05.in
./gen 1000 2 23426 > secret/heap06.in
./gen 100000 0 23554464 > secret/heap07.in
./gen 100000 1 5413265 > secret/heap08.in
./gen 100000 2 2312426 > secret/heap09.in

for infile in secret/*.in
do
	./sol < $infile > ${infile%%.*}.ans
done
