#include <bits/stdc++.h>

using namespace std;


vector<int> g[1000001];
int dp1[1000001], dp2[1000001];

void dfs(int v, int p) {
    dp1[v] = 1;
    dp2[v] = 0;
    for (int c : g[v]) {
        if (c != p) {
            dfs(c, v);
            dp1[v] += dp2[c];
            dp2[v] += max(dp1[c], dp2[c]);
        }
    }
}

int main() {
    int n, root = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            root = i;
            continue;
        }
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(root, root);
    cout << max(dp1[root], dp2[root]);
    return 0;
}