#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector<double> numbers;
	vector<char> ops;
	for(int i = 0; i < s.size(); ++i){
		if(i%2) ops.push_back(s[i]);
		else numbers.push_back(s[i] - '0');
	}
	// steg 1: divisioner
	for(int i = 0; i < ops.size(); ++i){
		if(ops[i] == '/'){
			int arg1 = i;
			int arg2 = i + 1;
			numbers[arg1] /= numbers[arg2];
			numbers.erase(numbers.begin() + arg2);
			ops.erase(ops.begin() + i);
			i--;
		}
	}
	// steg 2: multiplikationer
	for(int i = 0; i < ops.size(); ++i){
		if(ops[i] == '*'){
			int arg1 = i;
			int arg2 = i + 1;
			numbers[arg1] *= numbers[arg2];
			numbers.erase(numbers.begin() + arg2);
			ops.erase(ops.begin() + i);
			i--;
		}
	}
	double ans = numbers[0];
	for(int i = 0; i < ops.size(); ++i){
		if(ops[i] == '+') ans += numbers[i+1];
		if(ops[i] == '-') ans -= numbers[i+1];
	}
	cout << setprecision(10) << fixed;
	cout << ans << endl;
}
