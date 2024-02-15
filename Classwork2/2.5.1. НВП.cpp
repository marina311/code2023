#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> a(n), pos(n + 1), dp(n + 1, INF);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int length = 0;
    pos[0] = -1;
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            pos[j] = i;
            length = max(length, j);
        }
    }
    cout << length;
    return 0;
}