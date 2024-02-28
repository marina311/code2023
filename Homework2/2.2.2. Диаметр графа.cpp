#include <bits/stdc++.h>

using namespace std;

using namespace std;

const int MAX_N = 100;
const int INF = 1000000000;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> a(MAX_N + 1, vector<int>(MAX_N + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                a[i][j] = n * 1000;
            }
        }
        a[i][i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                if (a[j][i] + a[i][k] < a[j][k])
                    a[j][k] = a[j][i] + a[i][k];

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] > ans) {
                ans = a[i][j];
            }
        }
    }

    cout << ans << "\n";

    ans = INF;
    for (int i = 1; i <= n; ++i) {
        int k = 0;
        for (int j = 1; j <= n; ++j) {
            k = max(k, a[i][j]);
        }
        ans = min(ans, k);
    }
    cout << ans;
    return 0;
}
