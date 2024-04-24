#include <bits/stdc++.h>

using namespace std;


vector<vector<long long>> g(100001);

vector<long long> tin, tout;
long long timer = 0;
vector<vector<long long>> up;
long long l = 0;

void dfs(long long v, long long p = 0) {

    tin[v] = ++timer;
    up[v][0] = p;
    for (long long i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (size_t i = 0; i < g[v].size(); ++i) {
        long long to = g[v][i];
        if (to != p)
            dfs(to, v);
    }
    tout[v] = ++timer;
}


bool upper(long long a, long long b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

long long lca(long long a, long long b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (long long i = l; i >= 0; --i)
        if (!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}


int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int x = 0;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    vector<long long> a(3);
    cin >> a[1] >> a[2];
    long long x = 0, y = 0, z = 0;
    cin >> x >> y >> z;

    for (int i = 3; i <= 2 * m; i++) {
        a.push_back((x * a[i - 2] + y * a[i - 1] + z) % n);
    }

    tin.resize(n, 0), tout.resize(n, 0), up.resize(n);
    l = 1;
    while ((1 << l) <= n) ++l;
    for (long long i = 0; i < n; ++i) up[i].resize(l + 1, 0);

    dfs(0, 0);

    long long cnt = 0;
    long long lst = lca(a[1], a[2]);
    cnt += lst;

    for (long long i = 2; i <= m; i++) {
        long long x1 = (a[2 * i - 1] + lst) % n;
        long long x2 = a[2 * i];
        long long res = lca(x1, x2);
        cnt += res;
        lst = res;
    }
    cout << cnt;
    return 0;
}