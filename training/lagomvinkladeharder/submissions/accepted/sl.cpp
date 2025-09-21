#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Eisenstein integers: https://en.wikipedia.org/wiki/Eisenstein_integer
// a + omega*b, where omega^3 = 1, omega^2 = conj(omega) = -1-omega
struct Num {
	ll a, b;
	Num conj() const { return {a - b, -b}; }
};

Num operator*(Num a, Num b) {
	ll y = a.b * b.b;
	return {a.a * b.a - y, a.b * b.a + a.a * b.b - y};
}
bool operator==(Num a, Num b) { return a.a == b.a && a.b == b.b; }
Num& operator*=(Num& a, Num b) { return a = a * b; }
Num& operator*=(Num& a, int b) { a.a *= b; a.b *= b; return a; }
ostream& operator<<(ostream& os, Num a) {
	return os << '(' << a.a << ", " << a.b << ')';
}

template<class F>
void rec(vector<pii>& m, vector<Num>& facts, int ind, Num cur, F f) {
	if (ind == sz(m)) {
		f(cur);
		return;
	}

	int p = m[ind].first;
	int co = m[ind].second;
	if (p % 3 != 1) {
		// If p is 2 (mod 3), p cannot be factored; cur must have exactly 'co'
		// factors p and nothing else.
		// If p is 3, p can be factored, but we still don't want to split it
		// up; the factor and its conjugate are related by a unit.
		for (int i = 0; i < co; i++)
			cur *= p;
		rec(m, facts, ind+1, cur, f);
	} else {
		Num n = facts[ind];
		Num tmp{1,0};
		vector<Num> pws;
		pws.reserve(2*co+1);
		pws.push_back(tmp);
		rep(i,0,2*co) {
			tmp = tmp * n;
			pws.push_back(tmp);
		}
		rep(i,0,2*co+1) {
			rec(m, facts, ind+1, cur * pws[i] * pws[2*co - i].conj(), f);
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	const int N = 200000;

	// We care about factors a + omega*b s.t. a^2 + b^2 - ab <= N, and wlog 0 <= a, b.
	// N >= a^2 + b^2 - ab = a^2 - 2a*(b/2) + (b/2)^2 + 3/4*b^3 >= 3/4*b^2,
	// so b <= sqrt(4/3 * N), and similarly for a.
	int sq = (int)sqrt(N * 4 / 3) + 10;
	vector<Num> factors(N+1);
	rep(a,0,sq+1) rep(b,0,sq+1) {
		int x = a*a + b*b - a*b;
		if (x <= N) {
			assert((Num{a, b} * Num{a, b}.conj() == Num{x, 0}));
			factors[x] = Num{a, b};
		}
	}

	vi fact(N+1, 1);
	fact[0] = fact[1] = 0;
	for (int p = 2; p*p <= N; p++) {
		if (fact[p] == 1) {
			for (int i = p*p; i <= N; i += p) fact[i] = p;
		}
	}

	ll res = 0;
	vector<ll> resAt(N+1);
	vector<ll> ans(N+1);
	for (int c = 1; c <= N; c++) {
		int x = c;
		map<int, int> r;
		while (x != 1) {
			if (fact[x] == 1) {
				r[x]++;
				x = 1;
			} else {
				r[fact[x]]++;
				x /= fact[x];
			}
		}

		// Let r2 be the factorization of c.
		vector<pii> r2(all(r));

		// Let 'facts' contain factors for all primes that aren't 2 (mod 3) in r2.
		vector<Num> facts(sz(r2));
		rep(i,0,sz(r2)) {
			if (r2[i].first % 3 != 2) {
				facts[i] = factors[r2[i].first];
			}
		}

		rec(r2, facts, 0, Num{1, 0}, [&](Num x) {
			Num unit{1, 1};
			rep(it,0,6) {
				x *= unit;
				if (1 <= x.a && x.a <= x.b && x.b <= N) {
					assert(x.b >= c);
					resAt[x.b]++;
				}
			}
		});
		res += resAt[c];
		ans[c] = res;
	}

	// Sanity check: n <= 1000 matches brute-force
	if (0) for (int n = 1; n <= 1000; n++) {
		res = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				int k = (int)sqrt(i*i + j*j - i*j);
				if (k*k == i*i + j*j - i*j) res++;
			}
		}
		assert(ans[n] == res);
	}

	int n;
	while (cin >> n) cout << ans[n] << '\n';
}
