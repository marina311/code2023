#include <bits/stdc++.h>

using namespace std;
int a[101][101];

int main() {
    int n;
    cin >> n;
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v) {
            cin >> a[u][v];
        }
    for (int k = 0; k < n; ++k)

        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                a[u][v] = min(a[u][v], a[u][k] + a[k][v]);

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v)
            cout << a[u][v] << " ";
        cout << "\n";
    }

    return 0;
}