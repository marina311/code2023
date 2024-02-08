#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int l = -1, r = n - 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (x <= a[mid]) r = mid;
            else l = mid;
        }
        if (a[r] == x || r == 0 || a[r] - x < x - a[l]) cout << a[r] << "\n";
        else cout << a[l] << "\n";
    }
    return 0;
}