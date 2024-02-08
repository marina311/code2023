#include <bits/stdc++.h>

using namespace std;


int main() {

    long long w, h, n;
    cin >> w >> h >> n;
    long long l = 0, r = min(n * w, n * h);
    while (l + 1 < r) {
        long long mid = l + (r - l) / 2;
        if ((mid / w) >= n || (mid / h) >= n || (mid / w) * (mid / h) >= n) r = mid;
        else l = mid;
    }
    cout << r << "\n";


}