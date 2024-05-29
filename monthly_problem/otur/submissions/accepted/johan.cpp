#include <bits/stdc++.h>

using namespace std;

long long starts_with(const vector<int>& prefix) {
  vector<vector<vector<long long>>> ans(10, vector<vector<long long>>(prefix.size(), vector<long long>(2, -1)));
  function<long long(int, int, int)> it = [&](int at, int last, bool follows) {
    if (at == (int)prefix.size()) return 1LL;
    if (ans[last][at][follows] != -1) return ans[last][at][follows];
    long long a = 0;
    for(int i = 0; i <= 9; ++i){
      if(i > prefix[at] && follows) break;
      if(i == 3 && last == 1) continue;
      a += (long long) it(at + 1, i, follows && (i == prefix[at]));
    }
    return ans[last][at][follows] = a;
  };
  return it(0, 0, true) - 1;

}

int main(){
  int N;
  cin >> N;
  vector<int> ans;
  ans.push_back(9);
  while(starts_with(ans) < N) ans.push_back(9);
  ans[0] = 1;
  for(int i = 0; i < (int)ans.size(); i++){
    ans[i] = 0;
    while(starts_with(ans) < N) ans[i]++;
  }
  for(int i : ans) cout << i;
  cout << endl;
}
