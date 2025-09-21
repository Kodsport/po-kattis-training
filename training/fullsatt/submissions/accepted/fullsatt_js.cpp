#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	multiset<int> on;
	int ans = 0;
	for(int i = 1; i <= N - 1; ++i){
		while(on.size() && *on.begin() == i) on.erase(on.begin());
		int ai, x;
		cin >> ai;
		for(int j = 0; j < ai; ++j){
			cin >> x;
			if(on.size() == C) ans++;
			else on.insert(x);
		}
	}
	cout << ans << endl;
}
