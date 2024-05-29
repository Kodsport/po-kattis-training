#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(it, v) for(auto it = v.begin(); \
		it != v.end(); ++it)
#define all(x) x.begin(), x.end()
#define D(x) \
	cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int cin;

vector<bool> seen;
vector<set<int>> adj;
int idx = 1;

bool go(int at, vector<int>& order){
    if(seen[at]){
        return false;
    }
    seen[at] = true;

    if(idx == (int)order.size()){
        cout << "YES" << endl;
        exit(0);
    }

    while(adj[at].count(order[idx])){
        int nx = order[idx++];
        adj[at].erase(nx);
        adj[nx].erase(at);
        if(!go(nx, order)){
            return false;
        }
    }
    trav(it, adj[at]){
        if(!seen[*it]){
            return false;
        }
        adj[*it].erase(at);
    }
    adj[at].clear();

    return true;
}

int main() {
	int n, e;
	ignore = scanf("%d%d", &n, &e);
    adj.resize(n);
    seen.resize(n);
    rep(i,0,e){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> consume;
    int x;
    while(scanf("%d", &x) == 1) consume.push_back(x);
    if(consume.empty() || (int)consume.size() != n || !go(consume[0], consume)){
        cout << "NO" << endl;
    } 
}
