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

vector<LL> cal(LL a) {
    vector<LL> f(61);
    for (int i = 0; i < 61; i++) {
        LL N = a - (1LL << i) + 1;
        if (N < 0) {
            break;
        }
        LL rest = N % (1LL << i + 1) <= (1LL << i) ? N % (1LL << i + 1) : (1LL << i);
        f[i] = N / (1LL << i + 1) * (1LL << i) + rest;
    }
    return f;
}

void solve() {
    LL a, b;
    cin >> a >> b;
    vector<LL> num = cal(a);

    LL ans = 0;
    for (int i = 0; (b >> i) > 0; i++) {
        if ((b >> i) & 1) {
            ans += 1LL * num[i];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
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