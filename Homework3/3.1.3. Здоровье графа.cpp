#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100001;
vector<int> g[NMAX];
int parent[NMAX];
long long sz[NMAX], color[NMAX];
bool used[NMAX];
vector<pair<int, int>> edges;

void dfs(int v, int c) {
    used[v] = true;
    sz[v] = 1;
    color[v] = c;
    for (auto to: g[v]) {
        if (used[to]) continue;
        parent[to] = v;
        dfs(to, c);
        sz[v] += sz[to];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);

    }
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            parent[i] = -1;
            dfs(i, i);
        }
    int q;
    cin >> q;
    while(q--){
        int i;
        cin >> i;
        int u = edges[i-1].first;
        int v = edges[i-1].second;
        if (v == parent[u]) swap(u, v);
        long long ans = sz[v] * (sz[color[u]] - sz[v]);
        cout << ans << "\n";
    }
    return 0;
}