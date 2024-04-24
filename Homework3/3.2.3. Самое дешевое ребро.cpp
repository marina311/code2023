#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> a;
vector<int> p;
vector<int> h;
vector<vector<int>> mn;
int KMAX = 18;
int n;
const int INF = 1e7;
vector<vector<int>> dp;

void dfs(int v) {
    for (auto [u, c] : a[v]) {
        h[u] = h[v] + 1;
        mn[u][0]= c;
        dfs(u);
    }
}

void preprocess() {
    p[0] = 0;
    h[0] = 0;
    dfs(0);
    for (int i = 0; i <= KMAX; ++i) {
        for (int u = 0; u < n; ++u) {
            if (i == 0) {
                dp[u][i] = p[u];
            } else {
                dp[u][i] = dp[dp[u][i - 1]][i - 1];
                mn[u][i] = min(mn[dp[u][i - 1]][i - 1], mn[u][i - 1]);
            }
        }
    }
}

int lca(int v, int u) {
    int res = INF;
    if (h[v] > h[u]) {
        swap(v, u);
    }
    for (int i = KMAX; i >= 0; --i) {
        if (h[dp[u][i]] - h[v] >= 0) {
            res = min(res, mn[u][i]);
            u = dp[u][i];
        }
    }
    if (v == u) {
        return res;
    }
    for (int i = KMAX; i >= 0; --i) {
        if (dp[v][i] != dp[u][i]) {
            res = min(res, mn[u][i]);
            res = min(res, mn[v][i]);
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    res = min(res, mn[u][0]);
    res = min(res, mn[v][0]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    mn.resize(n, vector<int>(KMAX + 1, INF));
    dp.resize(n, vector<int>(KMAX + 1));
    a.resize(n);
    p.resize(n);
    h.resize(n);
    for (int i = 1; i < n; ++i) {
        int v, c;
        cin >> v >> c;
        p[i] = v - 1;
        a[v - 1].emplace_back(i, c);
    }
    preprocess();
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        int x = lca(u, v);
        cout << x << '\n';
    }
}