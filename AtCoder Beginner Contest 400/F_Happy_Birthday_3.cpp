#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> c(2 * n), x(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i + n] = c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    vector<vector<LL>> dp(2 * n, vector<LL> (2 * n));
    for (int i = 0; i < 2 * n; i++) {
        dp[i][i] = x[c[i]] + 1;
    }
    for (int len = 2; len <= 2 * n; len++) {
        for (int i = 0; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i][j - 1] + dp[j][j];
            for (int k = i; k < j; k++) {
                if (c[k] == c[j]) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + j - k + dp[k + 1][j - 1]);
                }
            }
        }
    }

    LL res = INF;
    for (int i = 0; i + n - 1 < 2 * n; i++) {
        res = min(res, dp[i][i + n - 1]);
    }
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