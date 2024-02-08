#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        cout << "? " << mid << endl;
        string c;
        cin >> c;
        if (c == ">=") l = mid;
        else r = mid;
    }
    cout << "! " << l << "\n";


}