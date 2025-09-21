#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, S_req;
    if (!(cin >> N >> S_req)) return 0;
    vector<int> S(N), P(N);
    for (int i = 0; i < N; ++i) cin >> S[i] >> P[i];

    int Smax = S_req;
    int answer = INF;

    // We need T at least 3 (för T=1 och T=2 skulle någon typ användas minst hälften).
    for (int T = 3; T <= Smax; ++T) {
        int L = (T - 1) / 2; // max antal per typ
        if (L <= 0) continue;
        if (1LL * N * L < T) continue; // omöjligt att få ihop T objekt utan att överskrida per-typ-gräns

        // dp[t][s] = min kostnad att välja t raketer med total storslagenhet s (cap s till S_req)
        vector<vector<int>> dp(T+1, vector<int>(Smax+1, INF));
        dp[0][0] = 0;

        for (int i = 0; i < N; ++i) {
            int cnt = min(L, T); // max kopior vi kan ta av typ i
            // binär nedbrytning av cnt
            int take = 1;
            vector<tuple<int,int,int>> items; // (w, val, cost) där w = antal raketer, val = storslagenhet, cost = kostnad
            int remaining = cnt;
            while (remaining > 0) {
                int use = min(take, remaining);
                int w = use;
                int val = use * S[i];
                if (val > Smax) val = Smax; // capera på Smax
                int cost = use * P[i];
                items.emplace_back(w, val, cost);
                remaining -= use;
                take <<= 1;
            }
            // 0/1 uppdatering för varje pseudo-item
            for (auto &it : items) {
                int w, val, cost;
                tie(w, val, cost) = it;
                for (int t = T; t >= w; --t) {
                    for (int s = 0; s <= Smax; ++s) {
                        if (dp[t-w][s] == INF) continue;
                        int ns = s + val;
                        if (ns > Smax) ns = Smax;
                        dp[t][ns] = min(dp[t][ns], dp[t-w][s] + cost);
                    }
                }
            }
        }

        // kolla om vi kan uppnå >= S_req med exakt T raketer
        if (dp[T][Smax] < answer) answer = dp[T][Smax];
    }

    if (answer == INF) {
        // Om ingen giltig lösning hittades (teoretiskt kan hända) - skriv t.ex. -1
        cout << "-1\n";
    } else {
        cout << answer << "\n";
    }

    return 0;
}
