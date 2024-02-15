#include <bits/stdc++.h>

using namespace std;
int d[101], used[101];
vector<int> g[101];


void bfs(int u) {
    queue<int> qu;
    qu.push(u);
    used[u] = 1;
    d[u] = 0;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto to: g[u])
            if (!used[to]) {
                qu.push(to);
                used[to] = 1;
                d[to] = d[u] + 1;
            }
    }
}


int main() {
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v) {
            int x;
            cin >> x;
            if (x) g[u].push_back(v);
        }
    bfs(s);
    cout << d[f];
    return 0;
}