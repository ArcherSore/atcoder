#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 5005;
double dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<double> pre(n + 1);
    double tmp = 1.0;
    for (int i = 1; i <= n; i++) {
        pre[i] = tmp + pre[i - 1];
        tmp *= 0.9;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 0.9 * dp[i - 1]+ p[i];
        for (int j = i; j >= 1; j--) {
            dp[j] = max(0.9 * dp[j - 1] + p[i], dp[j]);
        }
    }

    double ans = -1200.0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i] / pre[i] - 1200.0 / sqrt(double(i)));
    }
    printf("%.8lf\n", ans);
    return 0;
}