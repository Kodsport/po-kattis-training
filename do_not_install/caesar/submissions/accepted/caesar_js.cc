#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
  string indata;
  cin >> indata;
  for(int i = 0; i < indata.size(); ++i){
    char c = indata[i] - 'a';
    c = (c - N + 26) % 26;
    indata[i] = c + 'a';
  }
  cout << indata << endl;

}
