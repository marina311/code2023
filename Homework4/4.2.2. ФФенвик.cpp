#include <bits/stdc++.h>

using namespace std;
int n;
const long long INF = 1e9 + 1;
vector<vector<long long>> t;
vector<pair<int, int>> coords;
vector<long long> weights;
vector<int> x_coords;
vector<vector<int>> y_coords;

void compress(vector<int> &a) {
    a.push_back(-1);
    a.push_back(INF);
    sort(a.begin(), a.end());
    unique(a.begin(), a.end());
}

long long sum(int rx, int ry) {
    long long res = 0;
    int x = upper_bound(x_coords.begin(), x_coords.end(), rx) - x_coords.begin() - 1;

    for (int i = x; i > 0; i -= i & -i) {
        int y = upper_bound(y_coords[i].begin(), y_coords[i].end(), ry) - y_coords[i].begin() - 1;
        for (int j = y; j > 0; j -= j & -j)
            res += t[i][j];
    }
    return res;
}

void add(int x, int y, int d) {
    int x0 = lower_bound(x_coords.begin(), x_coords.end(), x) - x_coords.begin();
    for (int i = x0; i < x_coords.size(); i += i & -i) {
        int y0 = lower_bound(y_coords[i].begin(), y_coords[i].end(), y) - y_coords[i].begin();
        for (int j = y0; j < y_coords[i].size(); j += j & -j)
            t[i][j] += d;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        coords.push_back({x, y});
        weights.push_back(w);
        x_coords.push_back(x);
    }
    compress(x_coords);
    t.resize(x_coords.size());
    y_coords.resize(x_coords.size());

    // для каждой вершины дерева фенвика по х соберем свой список y 
    for (int i = 0; i < n; ++i) {
        int x0 = lower_bound(x_coords.begin(), x_coords.end(), coords[i].first) - x_coords.begin();
        for (int x = x0; x < x_coords.size(); x += x & -x)
            y_coords[x].push_back(coords[i].second);
    }
    for (int i = 0; i < x_coords.size(); ++i) {
        compress(y_coords[i]);
        t[i].resize(y_coords[i].size(), 0);
    }

    for (int i = 0; i < n; ++i) {
        add(coords[i].first, coords[i].second, weights[i]);
    }

    cin >> q;
    vector<int> ans;
    while (q--) {
        string s;
        cin >> s;
        if (s == "change") {
            int i, z;
            cin >> i >> z;
            i--;
            add(coords[i].first, coords[i].second, z - weights[i]);
            weights[i] = z;
        } else {
            int rx, ry;
            cin >> rx >> ry;
            cout << sum(rx, ry) << "\n";
        }
    }
    return 0;
}