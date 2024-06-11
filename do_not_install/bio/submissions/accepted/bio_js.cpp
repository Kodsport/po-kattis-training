#include <iostream>

using namespace std;

int main() {
	int platser = 0;
	int sallskap = 0;
	cin >> platser >> sallskap;

	int answer = 0;

	for(int i = 0; i < sallskap; ++i){
		int x = 0;
		cin >> x;

		if(x > platser){
			answer++;
		} else {
			platser = platser - x;
		}
	}

	cout << answer << endl;
}
