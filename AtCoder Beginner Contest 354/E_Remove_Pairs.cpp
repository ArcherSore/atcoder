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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
    }

    vector<int> dp(1 << n, -1);
    dp[0] = 0; // init
    for (int i = 1; i < (1 << n); i++) {
        int f = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // if card_j and card_k exist in state i
                if ((i >> j) & 1 && (i >> k) & 1) {
                    // if card_j and card_k has one side to be the same
                    // and the new state removed card_j and card_k is 0 (has been updated && who go last wins)
                    if ((a[j] == a[k] || c[j] == c[k]) && dp[i ^ (1 << j) ^ (1 << k)] == 0) {
                        f = 1;
                    }
                }
                
            }
        }
        dp[i] = f;
    }
    cout << (dp.back() ? "Takahashi" : "Aoki") << '\n';
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