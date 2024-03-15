#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> p;
vector<int> d;
int KMAX = 16;
int n;
vector<vector<int>> dp;

void dfs(int u) {
    for (auto to: g[u])
        if (p[u] != to) {
            p[to] = u;
            d[to] = d[u] + 1;
            dfs(to);
        }
}

void preprocess() {
    p[0] = 0;
    d[0] = 0;
    dfs(0);
    for (int i = 0; i <= KMAX; ++i)
        for (int u = 0; u < n; ++u) {
            if (i == 0) dp[u][i] = p[u];
            else dp[u][i] = dp[dp[u][i - 1]][i - 1];
        }
}

int lca(int v, int u) {
    if (d[v] > d[u]) swap(v, u);
    for (int i = KMAX; i >= 0; --i)
        if (d[dp[u][i]] - d[v] >= 0)
            u = dp[u][i];
    if (v == u) return v;
    for (int i = KMAX; i >= 0; --i)
        if (dp[v][i] != dp[u][i]) {
            v = dp[v][i];
            u = dp[u][i];
        }
    return p[v];
}


int main() {
    cin >> n;
    dp.resize(n, vector<int>(KMAX));

    g.resize(n);
    p.resize(n);
    d.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
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
        cout << d[u] + d[v] -2 * d[x] << "\n";
    }
}