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
const int N = 1000;
const int Z = 26;

void solve() {
    // init
    vector<vector<int>> C(N + 1, vector<int> (N + 1));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
    }

    int k;
    cin >> k;
    vector<int> c(Z + 1), sc(Z + 1);
    for (int i = 1; i <= Z; i++) {
        cin >> c[i];
        sc[i] = sc[i - 1] + c[i];
    }
    vector<vector<int>> f(Z + 1, vector<int> (N + 1));
    for (int i = 0; i <= Z; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= Z; i++) {
        for (int j = 1; j <= min(k, sc[i]); j++) {
            for (int t = 0; t <= min(j, c[i]); t++) {
                f[i][j] = (f[i][j] + (1LL * f[i - 1][j - t] * C[j][t]) % MOD) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= min(k, sc[Z]); i++) {
        ans = (ans + f[Z][i]) % MOD;

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