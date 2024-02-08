#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> p2;
    for (long long i = 1; i * i <= NMAX; ++i)
        p2.insert(i * i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long res = 0;
        for (auto x: p2) {
            if (2 * x > n) break;
            int x1 = int(sqrt(n - x + 1e-7));
            if (x1 * x1 == n - x) {
                res += 2;
                if (2 * x == n) res--;
            }
        }
        cout << res << "\n";
    }
}