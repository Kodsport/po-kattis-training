#include <map>
#include <string>

using namespace std;

map<string, string> katalog;

void uppdateraNummer(string namn, string nummer){
  katalog[namn] = nummer;
}

bool raderaNummer(string namn){
  return katalog.erase(namn);
}

string uppslagning(string namn){
  map<string, string>::iterator it = katalog.find(namn);
  if(it != katalog.end()){
    return it->second;
  } else return "finns ej";
}
