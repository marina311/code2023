#include<bits/stdc++.h>

using namespace std;

const int INF = 10000000;

signed main() {
    int n, s;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> s;
    vector<int> dp(s + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= s; ++i) {
        for (auto x: a) {
            if (i - x >= 0 && dp[i - x] < dp[i])
                dp[i] = dp[i - x];
        }
        dp[i]++;
    }
    if (dp[s] < INF) {
        cout << dp[s] << "\n";
        int k = s;
        while (k > 0) {
            for (auto x:a) {
                if (k - x >= 0 && dp[k] == dp[k - x] + 1) {
                    cout << x << " ";
                    k -= x;
                    break;
                }
            }
        }
    } else cout << "-1";

    return 0;
}