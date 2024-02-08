#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long f = 1;
    if (n >= 1000003)
        cout << 0;
    else {
        for (int i = 2; i <= n; ++i) {
            f = (f * i) % 1000003;
        }
        cout << f << "\n";
    }
    return 0;
}