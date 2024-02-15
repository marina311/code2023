#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a.push_back({x, -1});
        a.push_back({y, m});
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (auto t: a) {
        if (t.second == -1) cnt++;
        else if (t.second == m) cnt--;
        else ans.push_back({t.second, cnt});

    }
    sort(ans.begin(), ans.end());
    for (auto t: ans)
        cout << t.second << " ";
    return 0;
}