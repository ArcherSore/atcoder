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

int dig(LL x) {
    int n = 0;
    while (x) {
        n++;
        x /= 10;
    }
    return n;
}

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

LL inverse(LL a) {
    return fpow(a, MOD - 2);
}

void solve() {
    LL n;
    cin >> n;

    int w = dig(n);
    cout << (n % MOD) * (1 - fpow(fpow(10, w), n)) % MOD * inverse(1 - fpow(10, w)) % MOD;
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