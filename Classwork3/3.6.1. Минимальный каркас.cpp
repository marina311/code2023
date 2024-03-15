#include <bits/stdc++.h>

using namespace std;
const int maxn = 200000;
const int INF = 1e9;
vector<pair<int, int>> g[maxn];
set<pair<int, int> > q;
bool used[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    int d[maxn];
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--;
        v--;
        g[u].push_back({v, weight});
        g[v].push_back({u, weight});
    }
    for (int i = 0; i < n; ++i) {

        d[i] = i == 0 ? 0 : INF;
        q.insert({d[i], i});
    }

    long long s = 0;
    while (!q.empty()) {
        int v = q.begin()->second;
        used[v] = true;
        s += d[v];
        q.erase(q.begin());

        for (auto e: g[v]) {
            int u = e.first, w = e.second;
            if (!used[u] && w < d[u]) {
                q.erase({d[u], u});
                d[u] = w;
                q.insert({d[u], u});
            }
        }
    }
    cout << s;

    return 0;
}