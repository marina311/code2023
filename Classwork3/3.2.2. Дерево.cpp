#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000001;
vector<int> g[NMAX];
int color[NMAX], res[NMAX];
set<int> s[NMAX];


void dfs(int v) {
    s[v].insert(color[v]);
    for (auto to: g[v]) {
        dfs(to);
        if (s[v].size() < s[to].size()) s[v].swap(s[to]);
        s[v].insert(s[to].begin(), s[to].end());
        s[to].clear();

    }
    res[v] = s[v].size();
}

int main() {
    int n, root;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p >> c;
        p--;
        color[i] = c;
        if (p == -1) {
            root = i;
            continue;
        }
        g[p].push_back(i);

    }
    dfs(root);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";


    return 0;
}