#include <bits/stdc++.h>

using namespace std;
vector<set<int>> g;
vector<bool> used;

void dfs(int u) {

    used[u] = 1;
    for (auto v: g[u])
        if (!used[v]) {
            dfs(v);
        }
}


int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u != v) {
            g[v - 1].insert(u - 1);
            g[u - 1].insert(v - 1);
        }
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << "NO";
            return 0;
        }

    }
    cout << "YES";
    return 0;
}