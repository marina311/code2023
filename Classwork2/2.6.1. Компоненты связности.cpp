#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100001;
vector<int> g[NMAX];
int used[NMAX];
int comp = 0;

void dfs(int u) {
    used[u] = comp;
    for (auto v:g[u]) {
        if (!used[v]) dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }


    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            comp++;
            dfs(i);
        }

    cout << comp << "\n";
    for (int i = 0; i < n; ++i)
        cout << used[i] << " ";

    return 0;
}