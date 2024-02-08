#include <bits/stdc++.h>

using namespace std;


int main() {

    unsigned long long n, x, y;

    cin >> n;
    vector<unsigned long long> a(n), pref(n + 1, 0);
    cin >> x >> y >> a[0];
    for (int i = 1; i < n; ++i) {
        a[i] = (x * a[i - 1] + y) % (1 << 16);

    }
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    unsigned long long m, z;
    long long t;
    cin >> m;
    if (m == 0) cout << 0;
    else {
        vector<unsigned long long> b(2 * m), c(2 * m);
        cin >> z >> t >> b[0];
        c[0] = b[0] % n;
        for (int i = 1; i < 2 * m; ++i) {
            b[i] = (z * b[i - 1] % (1 << 30) + t + (1 << 30)) % (1 << 30);
            c[i] = b[i] % n;
        }
        unsigned long long ans = 0;
        for (int i = 0; i < m; ++i) {
            int l = min(c[2 * i], c[2 * i + 1]);
            int r = max(c[2 * i], c[2 * i + 1]);
            ans += pref[r + 1] - pref[l];

        }
        cout << ans;
    }
    return 0;
}