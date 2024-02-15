#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100001;
vector<int> g[NMAX];
int used[NMAX];
vector<int> topsort;
bool flag = false;

void dfs(int u) {
    used[u] = 1;
    for (auto v:g[u]) {
        if (!used[v]) dfs(v);
        if (used[v] == 1) flag = true;
    }
    used[u] = 2;
    topsort.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }


    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            dfs(i);
        }
    if (flag) {
        cout << -1;
        return 0;
    }

    reverse(topsort.begin(), topsort.end());
    for (auto u: topsort)
        cout << u + 1 << " ";

    return 0;
}