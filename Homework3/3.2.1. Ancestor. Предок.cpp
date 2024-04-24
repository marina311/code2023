#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<int> tin;
vector<int> tout;
int t = 0;
void dfs(int v) {
    tin[v] = t++;
    for(auto u : a[v]){
        if (tin[u] == -1) dfs(u);
    }
    tout [v] = t;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int d = 0;
    a.resize(n);
    tin.resize(n, -1);
    tout.resize(n, -1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (v == 0){
            d = i;
            continue;
        }
        a[v - 1].push_back(i);
    }
    dfs(d);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (tin[u] <= tin[v] && tout[u] >= tout[v]) cout << 1;
        else cout << 0;
        cout << '\n';
    }
    return 0;
}