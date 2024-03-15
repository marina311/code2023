#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

unsigned int get(unsigned int mask, unsigned int i) { // i-ый бит
    return (mask >> i) & 1;
}

unsigned int inverse(unsigned int mask, unsigned int i) { // меняет i-ый бит на противоложный
    return mask ^ (1 << i);
}

unsigned int set1(unsigned int mask, unsigned int i) { // ультимативно ставит i-ый бит как 1
    return mask | (1 << i);
}

unsigned int set0(unsigned int mask, unsigned int i) { // ультимативно ставит i-ый бит ка к 0. Можно намного лучше
    return mask & ((int(-1)) - (1 << i));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (i == j) a[i][j] = INF;
        }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    vector<vector<int>> used(1 << n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> pred(1 << n, vector<pair<int, int>>(n, {-1, -1}));
    for (int i = 0; i < n; ++i)
        dp[set1(0, i)][i] = 0;


    for (unsigned int mask = 1; mask < 1 << n; ++mask)
        for (unsigned int last = 0; last < n; ++last) {
            if (!get(mask, last)) continue;
            for (int j = 0; j < n; ++j) {
                if (get(mask, j)) continue;
                unsigned int new_mask = set1(mask, j);
                if (!used[new_mask][j] || dp[new_mask][j] > dp[mask][last] + a[last][j]) {
                    used[new_mask][j] = true;
                    dp[new_mask][j] = dp[mask][last] + a[last][j];
                    pred[new_mask][j] = {mask, last};
                }
            }
        }
    int ans = INF;
    pair<int, int> p;
    for (int i = 0; i < n; ++i)
        if (ans > dp[(1 << n) - 1][i]) {
            ans = min(ans, dp[(1 << n) - 1][i]);
            p = {(1 << n) - 1, i};
        }
    cout << ans << "\n";
    vector<int> res;

    while (p.second != -1) {
        res.push_back(p.second);
        p = pred[p.first][p.second];
    }
    for (auto x: res)
        cout << x + 1 << " ";


    return 0;
}
