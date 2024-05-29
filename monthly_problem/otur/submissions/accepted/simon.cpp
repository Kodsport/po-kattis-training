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

ll K;
vi cur;
map<pii, ll> mem;
void rec(int prev, int rem) {
  if (rem == 0) {
    if (!K) throw 0;
    --K;
    return;
  }
  if (mem.count(pii(prev, rem)) && K - mem[pii(prev, rem)] >= 0) {
    K -= mem[pii(prev, rem)];
    return;
  }
  ll K0 = K;
  rep(d,0,10) {
    if (d == 3 && prev == 1) continue;
    cur.push_back(d);
    rec(d, rem-1);
    cur.pop_back();
  }
  mem[pii(prev, rem)] = K0 - K;
}

int main() {
  cin.sync_with_stdio(false);
  cin >> K;
  --K;
  try {
    for (int dig = 1;; dig++) {
      rep(d0, 1, 10) {
        cur.assign(1, d0);
        rec(d0, dig-1);
      }
    }
  } catch(int) {
    trav(c, cur) cout.put((char)('0' + c));
    endl(cout);
  }
}
