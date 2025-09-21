#include <iostream>

using namespace std;

int cube(int x){
	return x * x * x;
}

int max(int x, int y){
	if(x > y){
		return x;
	} else {
		return y;
	}
}

int differens(int x, int y){
	return x - y;
}
/*
int main(){
	int x, y;
	cin >> x >> y;
	cout << cube(x) << endl;
	cout << max(x, y) << endl;
	cout << differens(x, y) << endl;
}
*/
