#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	if(N != M){
		cout << "Nope" << endl;
	} else {
		vector<int> values(N);
		for(int i = 0; i < N; i++){
			cin >> values[i];
		}
		for(int i = 1; i <= M; ++i){
			bool found = false;
			for(int j = 0; j < N; ++j){
				if(values[j] == i){
					found = true;
				}
			}
			if(!found){
				cout << "Nope" << endl;
				return 0;
			}
		}
		cout << "Bijektion" << endl;
	}
}
