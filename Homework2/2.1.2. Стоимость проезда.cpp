#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> dist;

void bfs(int u) {
    queue<int> qu;
    qu.push(u);
    dist[u] = 0;
    while (!qu.empty()) {
        u = qu.front();
        qu.pop();
        for (auto v:g[u])
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
    }
}

int main() {
    int n, s, m;
    cin >> n >> s >> m;
    s--;
    g.resize(n);
    dist.resize(n, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[v - 1].push_back(u - 1);
    }

    bfs(s);
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}