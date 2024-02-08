#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 1;
    a[1] = 2;
    for (int i = 2; i < n + 1; ++i)
        a[i] = a[i - 1] + a[i - 2];
    cout << a[n];
    return 0;
}