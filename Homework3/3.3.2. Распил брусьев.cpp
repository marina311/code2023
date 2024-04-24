#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, n;
    cin >> l >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = l;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int j = 1; j < n + 2; j++) {
        for (int i = j - 2; i >= 0; i--) {
            dp[i][j] = 1e9;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
            dp[i][j] += a[j] - a[i];
        }
    }
    cout << dp[0][n + 1] << "\n";
    return 0;
}