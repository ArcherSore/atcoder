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
using PII = pair<LL, LL>;

LL lowbit(LL x) {
    return x & -x;
}

void solve() {
    LL L, R, l, r, len;
    cin >> L >> R;
    vector<PII> res;
    while (L < R) {
        LL x = (L > 0 ? lowbit(L) : (1LL << 60));
        while (R - L < x) {
            x >>= 1;
        }
        res.push_back({L, L + x});
        L += x;
    }
    cout << (int)res.size() << '\n';
    for (auto [x, y] : res) {
        cout << x << " " << y << '\n';
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