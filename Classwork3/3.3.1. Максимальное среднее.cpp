#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<double>> dp(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) dp[i][i] = a[i];
    for (int len = 2; len <= n; ++len) {
        for (int left = 0; left + len <= n; ++left) {
            int right = left + len - 1;
            for (int mid = left; mid < right; ++mid) {
                dp[left][right] = max(dp[left][right], (dp[left][mid] + dp[mid + 1][right]) / 2);
            }
        }
    }

    cout << setprecision(12) << dp[0][n - 1];


    return 0;
}
