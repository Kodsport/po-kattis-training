#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void run() {
  int n = Int(2, Arg("maxn"));
  Space();
  int k = Int(1, Arg("maxk"));
  Endl();

  vi edge(n,-1);
  for (int i = 0; i < n; i++)
  {
    int a = Int(1, n);
    Space();
    int b = Int(1, n);
    Endl();
    a--; b--;
    assert(edge[a]==-1);
    edge[a]=b;
  }


  Eof();
}

