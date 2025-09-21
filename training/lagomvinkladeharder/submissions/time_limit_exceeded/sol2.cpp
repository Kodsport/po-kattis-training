#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n)) {
		int res = 0;
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				int k = (int)round(sqrt(i*i + j*j - i*j));
				if (k*k == i*i + j*j - i*j && k <= n && k > 0) {
					res++;
				}
			}
		}

		printf("%d\n", res);
	}
	return 0;
}
