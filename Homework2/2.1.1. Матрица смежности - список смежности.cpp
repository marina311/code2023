#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '1')
                g[i].push_back(j);
        }
    for (int i = 0; i < n; ++i) {
        cout << g[i].size() << " ";
        for (auto x:g[i])
            cout << x + 1 << " ";
        cout << "\n";
    }
    return 0;
}