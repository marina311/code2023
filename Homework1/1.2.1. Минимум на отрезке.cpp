#include <bits/stdc++.h>


using namespace std;


int main() {
    deque<int> st;
    vector<int> a;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(1e9);
    for (int i = 0; i < k; ++i) {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        st.push_back(i);
    }
    for (int i = k; i <= n; ++i) {
        cout << a[st.front()] << "\n";
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        if (!st.empty() && st.front() <= i - k)
            st.pop_front();
        st.push_back(i);
    }
};