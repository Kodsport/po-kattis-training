#include "vectorfunktioner.h"
#include <iostream>
#include <vector>

using namespace std;

void dump(const vector<int>& v){
  for(int i = 0; i < (int)v.size(); ++i){
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main(){
  int n;
  cin >> n;
  vector<int> numbers(n);
  for(int i = 0; i < n; ++i){
    cin >> numbers[i];
  }
  cout << minsta(numbers) << endl;
  cout << summa(numbers) << endl;
  cout << veryOdd(numbers) << endl;
  dump(vartannat(numbers));
  reverse(numbers);
  dump(numbers);
}
