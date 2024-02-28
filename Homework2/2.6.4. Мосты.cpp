#include <bits/stdc++.h>
using namespace std;

int timer = 0;
int n;
vector <vector<pair<int, int> > > g;
vector<bool> visited;
vector<int> enter;
vector<int> rec;
vector<int> ans;

void dfs(int u, int parent)
{
    enter[u] = timer++;
    rec[u] = timer;
    visited[u] = true;
    for (auto edge : g[u])
    {
        int v = edge.first;
        int id = edge.second;
        if (v == parent)
            continue;
        if (!visited[v])
        {
            dfs(v, u);
            rec[u] = min(rec[u], rec[v]);
            if (rec[v] > enter[u])
                ans.push_back(id);
        }
        else
            rec[u] = min(rec[u], enter[v]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    visited.resize(n + 1);
    enter.resize(n + 1);
    rec.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(i, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto u : ans)
        cout << u << " ";
    cout << endl;
}

