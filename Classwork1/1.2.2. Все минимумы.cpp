#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 2), left(n + 1), right(n + 1);
    a[0] = -1e9;
    a[n + 1] = -1e9;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; ++i) {
        while (a[st.top()] > a[i]) st.pop();
        left[i] = st.top();
        st.push(i);

    }
    while (!st.empty()) st.pop();
    st.push(n + 1);
    for (int i = n; i > 0; --i) {
        while (a[st.top()] >= a[i]) st.pop();
        right[i] = st.top();
        st.push(i);

    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i] * (right[i] - i) * (i - left[i]);
    }
    cout << ans;
    return 0;
}