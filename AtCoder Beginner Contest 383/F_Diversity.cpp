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

const LL INF = 2e18;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;
    vector<vector<PII>> v(n + 1);
    for (int i = 0; i < n; i++) {
        int p, u, c;
        cin >> p >> u >> c;
        v[c].push_back({p, u});
    }

    vector<vector<LL>> dp(n + 1, vector<LL>(x + 1, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [p, u] : v[i]) {
            for (int j = x; j >= p; j--) {
                if (dp[i - 1][j - p] != -INF) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - p] + u + k);
                }
                if (dp[i][j - p] != -INF) {
                    dp[i][j] = max(dp[i][j], dp[i][j - p] + u);
                }
            }
        }
        for (int j = 0; j <= x; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    LL ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            ans = max(ans, dp[i][j]);
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