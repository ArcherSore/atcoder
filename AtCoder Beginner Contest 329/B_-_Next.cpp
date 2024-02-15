#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    int mx = 0, nxt = mx;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int> ());
    int tmp = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] != tmp) {
            cout << arr[i];
            return 0;
        }
    }
    return 0;
}