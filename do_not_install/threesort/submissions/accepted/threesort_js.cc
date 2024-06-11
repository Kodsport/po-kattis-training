#include <iostream>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a >> b >> c;

	if(b > c){
		int temp = b;
		b = c;
		c = temp;
	}

	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}

	if(b > c){
		int temp = b;
		b = c;
		c = temp;
	}

	cout << a << " " << b << " " << c << endl;

}
