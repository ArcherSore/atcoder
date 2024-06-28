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

const LL MOD = 1e8;

void solve() {
    LL n;
    cin >> n;
    LL res = 0;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
    }
    sort(a.begin(), a.end());
    res *= (n - 1);
    LL cnt = 0;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(a.begin() + i + 1, a.end(), MOD - a[i]) - a.begin();
        cnt += (n - p);
    }
    res -= cnt * MOD;
    cout << res << '\n';
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