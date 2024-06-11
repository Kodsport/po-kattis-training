#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	set<tuple<int, int, int>> s;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int k = (int)round(sqrt(i*i + j*j - i*j));
			if (k*k == i*i + j*j - i*j && k <= n && k > 0) {
				int ar[3] = {i, j, k};
				sort(ar, ar + 3);
				s.insert(make_tuple(ar[0], ar[1], ar[2]));
			}
		}
	}

	printf("%d\n", (int)s.size());
	return 0;
}
