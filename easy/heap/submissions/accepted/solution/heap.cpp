#include <set>

using namespace std;

multiset<int, greater<int>> tree;

int getMax(){
	return *tree.begin();
}


int getSize(){
	return tree.size();
}

void insert(int element){
	tree.insert(element);
}

void removeMax(){
	tree.erase(tree.begin());
}

