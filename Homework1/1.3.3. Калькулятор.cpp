#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pr(n + 1, -1);
    for (auto i = 2; i <= n; ++i) {
        a[i] = a[i - 1];
        pr[i] = i - 1;
        if (i % 2 == 0) {
            if (a[i] > a[i / 2]) {
                pr[i] = i / 2;
                a[i] = a[i / 2];
            }
        }
        if (i % 3 == 0) {
            if (a[i] > a[i / 3]) {
                pr[i] = i / 3;
                a[i] = a[i / 3];
            }
        }
        a[i]++;
    }
    cout << a[n] << '\n';
    vector<int> ans;
    while (n != -1) {
        ans.push_back(n);
        n = pr[n];
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
}
