#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        cout << g[i].size();
        sort(g[i].begin(), g[i].end());
        for (auto x: g[i]) {
            cout << " " << x + 1;
        }
        cout << "\n";
    }

    return 0;
}