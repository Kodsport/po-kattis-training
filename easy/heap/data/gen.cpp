#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define RANDOM 0
#define REVERSE 1
#define ZEROONE 2

int LIM = 1000000;


void gen_reverse(int ops){
	cout << 4*ops << endl;
	for(int i = 0; i < ops; ++i){
		cout << "0 " << i << endl;
		cout << "1" << endl;
	}
	for(int i = 0; i < ops; ++i){
		cout << "1" << endl;
		cout << "2" << endl;
	}
}

void gen_random(int ops){
	cout << ops << endl;
	int elements = 0;
	for(int i = 0; i < ops; ++i){
		int type = rand()%3;
		if(!elements && type) type = 0;
		if(type == 0){
			cout << "0 " << rand()%LIM << endl;
			elements++;
		}
		else if(type == 1) cout << "1" << endl;
		else if(type == 2){
			cout << "2" << endl;
			elements--;
		}
	}
}

void gen_01(int ops){
	LIM = 2;
	gen_random(ops);
}

int main(int argc, char** argv){
	if(argc < 4){
		printf("usage: ./gen ops type seed\n");
	}
	int ops = atoi(argv[1]);
	int type = atoi(argv[2]);
	int seed = atoi(argv[3]);
	srand(seed);

	if(type == RANDOM) gen_random(ops);
	else if(type == REVERSE) gen_reverse(ops);
	else if(type == ZEROONE) gen_01(ops);
	else assert(false && "bad generator type");
}
