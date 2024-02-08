#include <bits/stdc++.h>

using namespace std;

bool comp(string x, string y) {
    return x + y > y + x;
}

int main() {
    vector<string> a;
    string x;


    while (cin >> x) a.push_back(x);

    sort(a.begin(), a.end(), comp);
    for (auto x: a)
        cout << x;

    return 0;
}