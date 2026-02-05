#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i < int(to); ++i)

struct UF {
    vector<int> par;
    UF(int n) : par(n, -1) {}
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (-par[a] < -par[b]) swap(a, b);
        par[a] += par[b];
        par[b] = a;
        return true;
    }
    int find(int a) {
        return par[a] < 0 ? a : (par[a] = find(par[a]));
    }
};

int main() {
    cin.sync_with_stdio(false);
    int N, E;
    cin >> N >> E;
    UF uf(N);
    vector<tuple<int, int, int> > ed;
    ed.reserve(E);
    rep(i,0,E) {
        int a, b, c;
        cin >> a >> b >> c;
        ed.emplace_back(-c, a, b);
    }
    sort(all(ed));
    int comp = N;
    int k = 0;
    while (comp > 1) {
        int c, a, b;
        tie(c, a, b) = ed[k++];
        if (uf.join(a, b))
            --comp;
    }
    cout << -get<0>(ed[k-1]) << endl;
}
