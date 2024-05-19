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
    LL res1 = 0, res2 = 0;
    for (int i = 1; i <= 9; i++) {
        int x;
        cin >> x;
        res1 += x;
    }
    for (int i = 1; i <= 8; i++) {
        int x;
        cin >> x;
        res2 += x;
    }
    cout << res1 - res2 + 1 << '\n';
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