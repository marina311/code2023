#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, s;
    cin >> s >> n;
    vector<int> a(n);
    vector<bool> dp(s + 1, false);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int k = s; k > a[i] - 1; --k)
            if (dp[k - a[i]]) dp[k] = true;
    for (int i = s; i >= 0; --i)
        if (dp[i]) {
            cout << i;
            break;
        }
    return 0;
}