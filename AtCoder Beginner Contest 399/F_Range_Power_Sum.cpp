#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

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

LL C(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    return (C(n - 1, k) + C(n - 1, k - 1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, K;
    cin >> n >> K;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<LL>> dp(n + 1, vector<LL>(K + 1));
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= K; k++) {
            dp[i][k] = fpow(a[i], k);
            for (int j = 0; j <= k; j++) {
                dp[i][k] = (dp[i][k] + (fpow(a[i], j) * C(k, j) % MOD) * dp[i - 1][k - j] % MOD) % MOD;
            }
        }    
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + dp[i][K]) % MOD;
    }
    cout << res << '\n';

    return 0;
}