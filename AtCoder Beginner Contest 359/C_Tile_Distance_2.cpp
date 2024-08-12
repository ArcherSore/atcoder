// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    LL l, r;
    if (sy % 2) {
        if (sx >= 0) {
            r = (sx + 1) / 2 * 2;
        } else {
            r = (sx - 1) / 2 * 2;
        }
        l = r - 1;
    } else {
        l = sx / 2 * 2;
        r = l + 1;
    }

    LL k = abs(sy - ty);
    l -= k;
    r += k;

    if (l <= tx && tx <= r) {
        cout << k << '\n';
    } else {
        if (ty % 2) {
            if (tx < l) {
                cout << k + (l + 1) / 2 - (tx + 1) / 2 << '\n';
            } else {
                cout << k + (tx + 1) / 2 - (r + 1) / 2 << '\n';
            }
        } else {
            if (tx < l) {
                cout << k + l / 2 - tx / 2 << '\n';
            } else {
                cout << k + tx / 2 - r / 2 << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}