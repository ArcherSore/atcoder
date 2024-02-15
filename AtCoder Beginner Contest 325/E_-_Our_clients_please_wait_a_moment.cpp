#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
long long dp[MAXN][2];
long long d[MAXN][MAXN];

int main() {
    int n;
    long long A, B, C;
    scanf("%d%lld%lld%lld", &n, &A, &B, &C);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &d[i][j]);
        }
    }

    memset(dp, 0x7f, sizeof(dp));
    dp[1][0] = dp[0][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][1] = min(dp[i][1], min(dp[j][0] + d[j][i] * A, dp[j][1] + d[j][i] * B + C));
            dp[i][0] = min(dp[i][0], dp[j][0] + d[j][i] * A);
        }
        // printf("dp[%d] = %lld\n", i, dp[i]);
    }
    for (int i = n; i > 1; i--) {
        for (int j = n; j >= 1; j--) {
            dp[i][1] = min(dp[i][1], min(dp[j][0] + d[j][i] * A, dp[j][1] + d[j][i] * B + C));
            dp[i][0] = min(dp[i][0], dp[j][0] + d[j][i] * A);
        }
        // printf("dp[%d] = %lld\n", i, dp[i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][1] = min(dp[i][1], min(dp[j][0] + d[j][i] * A, dp[j][1] + d[j][i] * B + C));
            dp[i][0] = min(dp[i][0], dp[j][0] + d[j][i] * A);
        }
        // printf("dp[%d] = %lld\n", i, dp[i]);
    }
    for (int i = n; i > 1; i--) {
        for (int j = n; j >= 1; j--) {
            dp[i][1] = min(dp[i][1], min(dp[j][0] + d[j][i] * A, dp[j][1] + d[j][i] * B + C));
            dp[i][0] = min(dp[i][0], dp[j][0] + d[j][i] * A);
        }
        // printf("dp[%d] = %lld\n", i, dp[i]);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << endl;
    // }
    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}