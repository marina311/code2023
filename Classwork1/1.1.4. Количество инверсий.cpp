#include <bits/stdc++.h>

using namespace std;

long long res = 0L;

void merge(vector<long long> &arr, int left, int mid, int right) {
    int it1 = 0, it2 = 0;
    vector<long long> result(right - left);
    while (left + it1 < mid && mid + it2 < right) {
        if (arr[left + it1] <= arr[mid + it2]) {
            result[it1 + it2] = arr[left + it1];
            it1++;
        } else {
            result[it1 + it2] = arr[mid + it2];
            res += mid - left - it1;
            it2++;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = arr[left + it1];
        it1++;
    }

    while (mid + it2 < right) {
        result[it1 + it2] = arr[mid + it2];
        it2++;

    }

    for (int i = 0; i < result.size(); ++i)
        arr[left + i] = result[i];
}

void mergeSortRecursive(vector<long long> &arr, int left, int right) {
    if (right - left <= 1)
        return;

    int mid = (left + right) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid, right);
    merge(arr, left, mid, right);

}


int main() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<long long> arr(n, 0);
    unsigned int cur = 0;

    for (int i = 0; i < n; ++i) {
        cur = cur * a + b;
        arr[i] = (cur >> 8) % m;
    }

    mergeSortRecursive(arr, 0, n);
    cout << res;
    return 0;
}