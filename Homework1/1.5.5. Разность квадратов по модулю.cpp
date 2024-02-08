#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int MOD = 1000007;
    long long ans = ((a * a - b * b) % MOD + MOD) % MOD;
    cout << ans << "\n";
}