#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> d, maxtoleaf;
int ans = 1;

void dfs(int u, int p = -1) {
    vector<int> ch;
    for (auto v: g[u]) {
        if (v == p)continue;
        dfs(v, u);
        maxtoleaf[u] = max(maxtoleaf[u], maxtoleaf[v] + 1);
        ch.push_back(maxtoleaf[v]);
    }
    d[u] = maxtoleaf[u];
    if (ch.size() > 1) {
        sort(ch.rbegin(), ch.rend());
        d[u] = ch[0] + ch[1] + 1;
    }
    ans = max(ans, d[u]);

}


int main() {
    int n;
    cin >> n;
    g.resize(n);
    d.resize(n, 1);
    maxtoleaf.resize(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout << ans;
    return 0;
}