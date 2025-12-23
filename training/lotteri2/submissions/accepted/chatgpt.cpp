#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long T;
    cin >> N >> T;

    vector<long long> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    long long winning = 0;
    int total = 1 << N;

    for (int mask = 0; mask < total; mask++) {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sum += w[i];
            }
        }
        if (sum == T) {
            winning++;
        }
    }

    double probability = 100 * winning / double(total);
    cout << fixed << setprecision(10) << probability << "\n";
    return 0;
}
