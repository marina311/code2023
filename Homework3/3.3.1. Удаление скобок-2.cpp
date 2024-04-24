#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, n));
    vector<vector<bitset<120>>> ans(n + 1, vector<bitset<120>>(n + 1));

    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 0;
    };
    for (int len = 1; len <= n; ++len) {
        for (int left = 0; left + len <= n; ++left) {
            int right = left + len;
            for (int mid = left; mid < right; ++mid) {
                if (dp[left][mid] + dp[mid][right] < dp[left][right]) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid][right]);
                    ans[left][right] = ans[left][mid] | ans[mid][right];
                }

            }
            if (dp[left][right] > dp[left + 1][right] + 1) {
                dp[left][right] = min(dp[left][right], dp[left + 1][right] + 1);
                ans[left][right] = ans[left + 1][right];
            }
            if (dp[left][right] > dp[left][right - 1] + 1) {
                dp[left][right] = min(dp[left][right], dp[left][right - 1] + 1);
                ans[left][right] = ans[left][right - 1];
            }
            if ((s[left] == '(' && s[right - 1] == ')' || s[left] == '[' && s[right - 1] == ']' ||
                 s[left] == '{' && s[right - 1] == '}') &&
                dp[left][right] > dp[left + 1][right - 1]) {
                dp[left][right] = min(dp[left][right], dp[left + 1][right - 1]);
                ans[left][right] = ans[left + 1][right - 1];
                ans[left][right].set(left, 1);
                ans[left][right].set(right-1, 1);
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (ans[0][n].test(i))
            cout << s[i];
    }

    return 0;
}