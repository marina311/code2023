#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
bitset<N> a[N];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char k;
            cin >> k;
            a[i][j] = (k == '1');
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j][i])
                a[j] |= a[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (a[i][j]) ? 1 : 0;
        cout << "\n";
    }
    return 0;
}