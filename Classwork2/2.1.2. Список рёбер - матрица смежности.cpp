#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 0));

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u][v] = 1;
        a[v][u] = 1;;
    }

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v)
            cout << a[u][v];
        cout << "\n";
    }

    return 0;
}