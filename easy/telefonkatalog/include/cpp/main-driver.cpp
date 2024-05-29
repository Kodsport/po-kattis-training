#include "telefonkatalog.h"
#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    int op;
    cin >> op;
    string namn, nummer;
    cin >> namn;
    if(op == 0){
      cout << uppslagning(namn) << endl;
    } else if(op == 1){
      cout << raderaNummer(namn) << endl;
    } else if(op == 2){
      cin >> nummer;
      uppdateraNummer(namn, nummer);
    }
  }
}
