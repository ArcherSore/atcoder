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

const int MOD = 998244353;

LL dig_num(LL x) {
    LL num = 1;
    while (x) {
        num *= 10;
        x /= 10;
    }
    return num;
}

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = dig_num(a[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        b[i] += b[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        b[i] %= MOD;
    }
    LL res = 0;
    for (LL i = 1; i < n; i++) {
        res += (a[i] * b[i + 1]) % MOD;
        res += (a[i] * (i - 1)) % MOD;
        res %= MOD;
    }
    res += a.back() * (n - 1);
    res %= MOD;
    cout << res;
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