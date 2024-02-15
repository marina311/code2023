#include <bits/stdc++.h>

using namespace std;

struct edge {
    int a, b;
    long long cost;
};
const long long INF = (long long) 3e18;

vector<edge> e;
vector<int> used;
vector<vector<int>> g;

void dfs(int v) {
    used[v] = 1;
    for (auto to: g[v]) {
        if (!used[to])
            dfs(to);
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    start--;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        edge u;
        cin >> u.a >> u.b >> u.cost;
        u.a--;
        u.b--;
        e.push_back(u);
        g[u.a].push_back(u.b);
    }

    vector<long long> d(n, INF);
    d[start] = 0;
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                }
    }
    for (int j = 0; j < m; ++j)
        if (d[e[j].a] < INF)
            if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                d[e[j].b] = d[e[j].a] + e[j].cost;
                if (!used[e[j].b])
                    dfs(e[j].b);
            }

    for (int i = 0; i < n; ++i) {
        if (used[i]) cout << "-\n";
        else if (d[i] == INF) cout << "*\n";
        else cout << d[i] << "\n";
    }


    return 0;
}