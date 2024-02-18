#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <numeric>
using namespace std;

typedef long long LL;

bool check(vector<LL> &a, LL mid) {
    for (LL t : a) {
        mid += t;
        if (mid < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    LL n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    LL l = 0, r = 1e18, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(a, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    for (LL t : a) {
        l += t;
    }
    cout << l << '\n';
    return 0;
}