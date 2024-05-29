#include "heap.h"
#include <cassert>
#include <iostream>

using namespace std;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL); 

	int ops;
	cin >> ops;
	for(int i = 0; i < ops; ++i){
		int type;
		cin >> type;
		if(type == 0){
			int val;
			cin >> val;
			insert(val);
			cout << getSize() << endl;
		} else if(type == 1){
			cout << getMax() << endl;
		} else if(type == 2) {
			removeMax();
			cout << getSize() << endl;
		} else {
			assert(false && "invalid op");
		}
	}
}
