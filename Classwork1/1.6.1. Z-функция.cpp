#include <bits/stdc++.h>

using namespace std;

vector<int> z(string s) {
    int n = s.size();
    vector<int> zf(n, n);
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        zf[i] = max(0, min(right - i, zf[i - left]));
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]]) {
            zf[i]++;
            if (i + zf[i] > right) {
                left = i;
                right = i + zf[i];
            }
        }
    }
    return zf;
}

int main() {
    string s;
    cin >> s;
    for (auto x: z(s))
        cout << x << " ";

    return 0;
}