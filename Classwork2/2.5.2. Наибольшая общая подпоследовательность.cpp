#include <bits/stdc++.h>

using namespace std;


int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = "$" + a;
    b = "$" + b;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prev(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prev[i][j] = 1;
            } else if (dp[i][j - 1] > dp[i - 1][j]) {
                dp[i][j] = dp[i][j - 1];
                prev[i][j] = 2;
            } else {
                dp[i][j] = dp[i - 1][j];
                prev[i][j] = 3;
            }
        }
    vector<int> ans1, ans2;
    cout << dp[n][m] << "\n";
    int x = prev[n][m], i = n, j = m;
    while (x != -1) {
        if (x == 2)
            j--;
        else if (x == 3)
            i--;
        else {
            ans1.push_back(i);
            ans2.push_back(j);
            i--;
            j--;
        }
        x = prev[i][j];

    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    for (auto x: ans1) cout << x << " ";
    cout << "\n";
    for (auto x: ans2) cout << x << " ";
    return 0;
}