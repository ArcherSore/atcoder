#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e9;

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res *= a;
        }
        a *= a;
        x >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    LL sum = 0;
    for (int i = 0; i <= m; i++) {
        sum += fpow(n, i);
        if (sum > INF) {
            cout << "inf";
            return;
        }
    }
    cout << sum;
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