#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, w;

    Edge(int u, int w) : u(u), w(w) {};

};

vector<vector<Edge>> g;
vector<int> dist;
vector<int> parent;

void bfs(int u) {
    deque<int> qu;
    qu.push_back(u);
    dist[u] = 0;
    parent[u] = -1;
    while (!qu.empty()) {
        u = qu.front();
        qu.pop_front();
        for (auto v:g[u])
            if (dist[v.u] == -1) {
                if (v.w == 1) {
                    dist[v.u] = dist[u] + 1;
                    qu.push_back(v.u);
                } else {
                    dist[v.u] = dist[u];
                    qu.push_front(v.u);
                }
                parent[v.u] = u;
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, -1);
    parent.resize(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int cost = a[u] == a[v] ? 0 : 1;
        g[u].push_back(Edge(v, cost));
        g[v].push_back(Edge(u, cost));
    }

    bfs(0);

    if (dist[n - 1] == -1)
        cout << "impossible";
    else {
        vector<int> ans;
        cout << dist[n - 1] << " ";
        n--;
        while (n != -1) {
            ans.push_back(n);
            n = parent[n];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] + 1 << " ";
        }

    }

    return 0;
}