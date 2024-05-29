#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

set<int> adj[100005];
int pos=1;
int b[100005];
int n, e, L;
set<int> vis;

void dfs(int node){
	while(pos < n && adj[node].find(b[pos]) != adj[node].end()){
		dfs(b[pos++]);
	}
}

int main(){
	scanf("%d%d", &n, &e);
	rep(i,0,e){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].insert(b);
		adj[b].insert(a);
	}
	while(scanf("%d", b+L) != EOF){
		if(vis.find(b[L]) != vis.end()){
			//puts("NO");
			//return 0;
		}
		vis.insert(b[L]);
		++L;
	}
	if(L != n){
		puts("NO");
		return 0;
	}
	dfs(b[0]);
	puts(pos == n?"YES":"NO");
}
