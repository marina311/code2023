#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

signed main() {
    int n;
    cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t;
            cin >> t;
            g[i][j] = t == 'Y';
        }
    }
    vector<vector<int>> dp_open(1 << n, vector<int>(n, -INF));
    vector<vector<int>> dp_close(1 << n, vector<int>(n, -INF));
    for (int i = 0; i < n; i++) {
        dp_open[1 << i][i] = 0;
        dp_close[1 << i][i] = 0;
    }
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (g[j][i] and dp_open[mask ^ (1 << i)][j] + 2 > dp_close[mask][i]) {
                        dp_close[mask][i] = dp_open[mask ^ (1 << i)][j] + 2;
                    }
                    if (dp_close[mask ^ (1 << i)][j] > dp_open[mask][i]) {
                        dp_open[mask][i] = dp_close[mask ^ (1 << i)][j];
                    }
                }
            }
        }
    }
    int mx = -INF;

    for (auto &v: dp_close) {
        for (auto u: v) {
            mx = max(u, mx);
        }
    }
    cout << mx << "\n";
}