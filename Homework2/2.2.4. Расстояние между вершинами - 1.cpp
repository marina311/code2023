#include <bits/stdc++.h>

using namespace std;

const int INF = 2009000999;

int main() {
    int n, m, start, fin;

    cin >> n >> m >> start >> fin;
    start--, fin--;
    vector<vector<pair<int, int> >> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    set<pair<int, int>> unused; // set пар вида {dist[u], u}
    unused.insert({0, start});
    vector<int> dist(n, INF);
    dist[start] = 0;
    vector<int> prev(n, -1);
    while (!unused.empty()) {
        int u = unused.begin()->second;
        unused.erase((unused.begin()));
        for (auto edge: g[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                unused.erase({dist[v], v});
                dist[v] = dist[u] + w;
                prev[v] = u;
                unused.insert({dist[v], v});
            }
        }
    }

    cout << dist[fin] << "\n";
    vector<int> path;
    path.push_back(fin);
    while (prev[fin] != -1) {
        fin = prev[fin];
        path.push_back(fin);
    }
    reverse(path.begin(), path.end());
    for (auto x: path) cout << x + 1 << " ";
    return 0;
}