#include <iostream>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;

	cin >> a >> b >> c >> d >> e;

	int correct = 0;
	
	cin >> correct;
	
	if(correct >= a){
		cout << "A" << endl;
	} else if(correct >= b){
		cout << "B" << endl;
	} else if(correct >= c){
		cout << "C" << endl;
	} else if(correct >= d){
		cout << "D" << endl;
	} else if(correct >= e){
		cout << "E" << endl;
	} else {
		cout << "F" << endl;
	}
}
