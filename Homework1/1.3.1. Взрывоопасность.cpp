#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    a[0] = 1;
    a[1] = 3;
    for (auto i = 2; i <= n; ++i) {
        a[i] = 2 * a[i - 1] + 2 * a[i - 2];
    }
    cout << a[n];
}
