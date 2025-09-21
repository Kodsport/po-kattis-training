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
typedef vector<pii> vpi;

int main() {
	int n, e;
	ignore = scanf("%d%d", &n, &e);
    vector<vpi> adj(n);
    rep(i,0,e){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }
    int ans = 1000000;
    set<pii, greater<pii>> q;
    vector<int> best(n, 0);
    best[0] = 0;
    q.insert(pii(1000000, 0));
    while(!q.empty()){
        int cur, node, cost;
        tie(cost, cur) = *q.begin();
        q.erase(q.begin());
        best[cur] = cost;
        ans = min(cost, ans);
        trav(it, adj[cur]){
            tie(node, cost) = *it;
            if(cost > best[node]){
                if(best[node] != 1000000 && best[0] != 0){
                    q.erase(pii(best[node], node));
                }
                best[node] = cost;
                q.insert(pii(cost, node));
            }
        }
    }
    printf("%d\n", ans);
}
