#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> dist;
vector<int> ans;

void bfs(int u) {
    queue<int> qu;
    qu.push(u);
    dist[u] = 0;
    while (!qu.empty()) {
        u = qu.front();
        ans.push_back(u);
        qu.pop();
        for (auto v:g[u])
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    g.resize(n);
    dist.resize(n, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    bfs(s);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}