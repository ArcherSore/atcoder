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

const int MAXN = 2e5 + 10;

LL dp[MAXN][2][2]; 

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    if (s[0] == '0') {
        dp[0][1][0] = dp[0][1][1] = dp[0][0][1] = c[0];
    } else {
        dp[0][0][0] = dp[0][0][1] = dp[0][1][1] = c[0];
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            dp[i][0][0] = dp[i - 1][1][0];
            dp[i][0][1] = min(dp[i - 1][0][0], dp[i - 1][1][1]);
            dp[i][1][0] = c[i] + dp[i - 1][0][0];
            dp[i][1][1] = c[i] + min(dp[i - 1][1][0], dp[i - 1][0][1]);
        } else {
            dp[i][0][0] = c[i] + dp[i - 1][1][0];
            dp[i][0][1] = c[i] + min(dp[i - 1][0][0], dp[i - 1][1][1]);
            dp[i][1][0] = dp[i - 1][0][0];
            dp[i][1][1] = min(dp[i - 1][1][0], dp[i - 1][0][1]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << c[i] << '\n';
    //     cout << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << '\n';
    // }
    
    cout << min(dp[n - 1][0][1], dp[n - 1][1][1]) << '\n';
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