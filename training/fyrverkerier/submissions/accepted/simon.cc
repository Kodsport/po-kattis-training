#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int N, S;
	cin >> N >> S;
	assert(N >= 3);
	vi ss(N), cost(N);
	rep(i,0,N) {
		cin >> ss[i] >> cost[i];
	}
	int res = 1 << 29;
	vi dp[5];
	dp[0].assign(S+1, 1 << 29);
	dp[0][0] = 0;
	rep(used2,0,S/2+10) {
		rep(i,1,5) dp[i].assign(S+1, 1 << 29);
		rep(i,0,N) {
			for (int j = 4; j >= 1; --j) {
				rep(s,0,S+1) {
					int s2 = min(s + ss[i], S);
					dp[j][s2] = min(dp[j][s2], dp[j-1][s] + cost[i]);
				}
			}
		}
		res = min(res, dp[3][S]);
		res = min(res, dp[4][S]);
		dp[0].swap(dp[2]);
	}
	cout << res << endl;
}

