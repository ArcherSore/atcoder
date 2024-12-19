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
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int div, rating;
        cin >> div >> rating;
        if (div == 1) {
            if (r < 1600 || r >= 2800) {
                continue;
            }
            r += rating;
        } else {
            if (r < 1200 || r >= 2400) {
                continue;
            }
            r += rating;
        }
    }
    cout << r << '\n';
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