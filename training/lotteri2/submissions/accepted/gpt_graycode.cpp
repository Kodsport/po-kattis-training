#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long T;
    cin >> N >> T;

    vector<long long> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    long long winning = 0;
    long long sum = 0;

    int total = 1 << N;
    int prev_gray = 0;

    // mask = 0 (tom mängd)
    if (sum == T) {
        winning++;
    }

    for (int i = 1; i < total; i++) {
        int gray = i ^ (i >> 1);
        int diff = gray ^ prev_gray;   // exakt en bit satt

        int bit = __builtin_ctz(diff); // index på ändrad bit

        if (gray & (1 << bit)) {
            sum += w[bit];   // bit sattes
        } else {
            sum -= w[bit];   // bit togs bort
        }

        if (sum == T) {
            winning++;
        }

        prev_gray = gray;
    }

    double probability = 100*double(winning) / double(total);
    cout << fixed << setprecision(10) << probability << "\n";

    return 0;
}
