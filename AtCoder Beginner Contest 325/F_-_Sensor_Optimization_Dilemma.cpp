#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L1, C1, K1, L2, C2, K2;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    cin >> L1 >> C1 >> K1 >> L2 >> C2 >> K2;

    vector<int> dp(K1 + 1, K2 + 1); // 大小为K1 + 1, 初值为K2 + 1
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        // 枚举每个区间，只与i-1有关不需要定义状态
        for (int j = K1; j >= 0; j--) {
            int v = dp[j];
            dp[j] = K2 + 1;
            for (int k = j; k <= K1; k++) {
                int rem = max(D[i] - (k - j) * L1, 0);
                rem = (rem + L2 - 1) / L2;
                dp[k] = min(dp[k], v + rem);
            }
        }
    }
    long long ans = -1;
    for (int i = 0; i <= K1; i++) {
        if (dp[i] <= K2) {
            long long v = 1ll * i * C1 + 1ll * dp[i] * C2;
            if (ans == -1 || ans > v) {
                ans = v;
            }
        }
    }
    cout << ans << endl;
    return 0;
}