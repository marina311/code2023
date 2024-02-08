#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int f1 = 1, f2 = 1;
    for (int i = 0; i < n - 1; ++i) {
        int t = f2;
        f2 = (f1 + f2) % 1000003;
        f1 = t;
    }
    cout << f2 << "\n";
    return 0;
}