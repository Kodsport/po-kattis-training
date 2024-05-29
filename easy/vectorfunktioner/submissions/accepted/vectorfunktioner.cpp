#include <vector>
#include <algorithm>

using namespace std;

void reverse(vector<int>& vec){
  for(int i = 0; i < (int)vec.size()/2; ++i)
    swap(vec[i], vec[(int)vec.size() - i - 1]);
}

// Välj ut vartannat element ur en vektor (första, tredje, osv)
// och returnera en ny vektor med svaret.
// Du får inte modifiera vektorn, trots att den skickas som referens.
// Därför används "const" framför parametern.
vector<int> vartannat(const vector<int>& vec){
  vector<int> res;
  for(int i = 0; i < (int)vec.size(); i += 2){
    res.push_back(vec[i]);
  }
  return res;
}

// Returnera det minsta värdet i en vektor.
int minsta(const vector<int>& vec){
  return *min_element(vec.begin(), vec.end());
}

// Returnera summan av elementen i en vektor.
int summa(const vector<int>& vec){
  return accumulate(vec.begin(), vec.end(), 0);
}

// Räkna antalet udda heltal, som dessutom befinner
// sig på udda index (räknat noll-indexerat!)
int veryOdd(const vector<int>& suchVector){
  int ans = 0;
  for(int i = 1; i < (int)suchVector.size(); i += 2){
    ans += suchVector[i]%2;
  }
  return ans;
}
