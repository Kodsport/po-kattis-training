#include <vector>

using namespace std;

vector<int> tree(1);

int left(int idx){
	return 2 * idx;
}

int right(int idx){
	return 2 * idx + 1;
}

int parent(int idx){
	return idx / 2;
}

int getMax(){
	return tree[1];
}


int getSize(){
	return tree.size() - 1;
}

void bubbleUp(int idx){
	while(idx != 1 && tree[idx] > tree[parent(idx)]){
		swap(tree[idx], tree[parent(idx)]);
		idx = parent(idx);
	}
}

void bubbleDown(int idx){
	int mx = idx;
	while(true){
		if(left(idx) <= getSize() && tree[left(idx)] > tree[mx]) mx = left(idx);
		if(right(idx) <= getSize() && tree[right(idx)] > tree[mx]) mx = right(idx);
		if(mx == idx) break;
		swap(tree[idx], tree[mx]);
		idx = mx;
	}
}


void insert(int element){
	tree.push_back(element);
	bubbleUp(getSize());
}

void removeMax(){
	tree[1] = tree.back();
	tree.pop_back();
	bubbleDown(1);
}

