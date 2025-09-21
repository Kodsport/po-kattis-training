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

int N;

map<tuple<int,int,int,int>, int> memo;
int rec(int occ1, int occ2, int left2, int left3) {
	if (!occ1 && !occ2 && !left2 && !left3) return 0;
	int& res = memo[make_tuple(occ1, occ2, left2, left3)];
	if (res) return res;
	int fr = N - occ1 - occ2;
	int r = 1 << 29;
	rep(u3, 0, left3+1) {
		if (u3*3 > fr) break;
		rep(u2, 0, left2+1) {
			if (u2*2 + u3*3 > fr) break;
			int no1 = occ2 + u2*2, no2 = u3*3;
			if (!occ1 && !occ2 && !u2 && !u3) continue;
			r = min(r, rec(no1, no2, left2 - u2, left3 - u3));
		}
	}
	return res = r + 1;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> N; assert(N <= 20);
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	if (a1) assert(N >= 1);
	if (a2) assert(N >= 2);
	if (a3) assert(N >= 3);
	int M = a1+a2+a3; assert(M <= 50);
	int mintime = (a1 + a2*4 + a3*9 + N-1) / N;
	cout << max(rec(0, 0, a2, a3), mintime) << endl;
	return 0;
}

