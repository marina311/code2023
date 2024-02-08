#include <bits/stdc++.h>

using namespace std;


int main() {

    int k;
    cin >> k;
    char c;
    deque<int> d;
    vector<int> a;
    while (cin >> c) {
        int t = c - '0';
        a.push_back(t);
    }
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        while (!d.empty() > 0 && d.back() < a[i] && d.size() + n - i > k) d.pop_back();
        while (!d.empty() && d.front() < a[i] && d.size() + n - i > k) d.pop_front();
        if (d.size() < k) d.push_back(a[i]);
    }


    while (!d.empty()) {
        cout << d.front();
        d.pop_front();

    }


    return 0;
}

