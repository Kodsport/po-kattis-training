#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define sz(x) int(x.size())
typedef vector<int> vi;

vi out, indeg, rem;
int n, k, answer;

#define NEXT from = out[from]; indeg[from]--;

void link(int from, int steps){
  if(rem[from]) steps = rem[from];
  else{
    answer++;
  }
  while(--steps != 0){
    NEXT;
    rem[from] = max(rem[from], steps);
    steps = max(steps, rem[from]);
    if(indeg[from] != 0) return;
  }
  NEXT;
  if(indeg[from] == 0) link(from, k);
}

bool inside(int from, int to, int point){
  if(from < to) return from <= point && point <= to;
  return from <= point || point <= to;
}

int d(int from, int to, int c){
  if(from < to) return to - from;
  return c - from + to;
}

int main() {
  ignore = scanf("%d%d", &n, &k);
  out.resize(n);
  indeg.resize(n);
  rem.resize(n);
  rep(i,0,n){
    int a, b;
    ignore = scanf("%d%d", &a, &b);
    a--; b--;
    out[a] = b;
    indeg[b]++;
  }
  rem[0] = k + 1;
  vector<int> q;
  rep(i,0,n) if(indeg[i] == 0) q.push_back(i);
  for(int i : q) link(i, k);

  vector<int> status(n, -1);
  rep(i,0,n){
    if(status[i] == -1 && indeg[i] == 1){
      int at = i, er = 0;
      do {
        rem[at] = er = max(er, rem[at]);
        status[at] = max(status[at], er ? 1 : 0);
        if(er) er--;
        at = out[at];
      } while(at != i || er > rem[at]);
      vector<bool> cyc;
      at = i;
      do {
        cyc.push_back(status[at]);
        at = out[at];
      } while(at != i);
      if(count(cyc.begin(), cyc.end(), false) == 0) continue;
      if(sz(cyc) < k){
        answer++;
        continue;
      }
      int m = sz(cyc);
      vector<int> nx(m, -1);
      rep(i,0,m) if(!cyc[i]) nx[i] = i%m;
      for(int i = 0, j = 0; j < 3*m; ++j, i=(3*m - j)%m)
        if(nx[i] == -1) nx[i] = nx[(i+1)%m];
      int best = m;
#define NX(a) nx[(a + k)%m]
      rep(i,0,min(m,k)){
        int at = NX(i), dist = 0, cur = 0;
        while(dist < m){
          dist += d(at, NX(at), m), at = NX(at), cur++;
        }
        best = min(best, cur);
      }
      answer += best;
    }
  }
  printf("%d\n", answer);
}

