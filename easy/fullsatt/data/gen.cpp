#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b); ++i)

int main(){
	int N, C;
	cin >> N >> C;
	cout << N << ' ' << C << endl;
	rep(i,1,N){
		int x = rand()%200;
		cout << x;
		rep(j,0,x){
			cout << ' ' << rand()%(N - i) + (i + 1);
		}
		cout << endl;
	}
}
