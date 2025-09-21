#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<string> indata;

	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;
		indata.push_back(s);
	}

	for(int i = indata.size() - 1; i >= 0; i--){
		cout << indata[i] << endl;
	}

}
