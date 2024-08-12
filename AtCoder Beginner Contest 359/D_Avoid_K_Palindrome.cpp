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

void add(int &x, int a) {
    x = (x + a) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int mask = (1 << k) - 1;
    // precalculate all palindromes
    vector<int> is_palindrome(mask + 1);
    for (int i = 0; i <= mask; i++) {
        bool ok = 1;
        for (int j = 0; j < k; j++) {
            if ((i >> j & 1) != (i >> (k - j - 1) & 1)) {
                ok = 0;
                break;
            }
        }
        is_palindrome[i] = ok;
    }
    
    // dp
    vector<vector<int>> f(n + 1, vector<int> (mask + 1));
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int state = 0; state <= mask; state++) {
            if (f[i][state] == 0) {
                continue;
            }
            for (int t = 0; t < 2; t++) {
                if (s[i] == (t ^ 1) + 'A') {
                    continue;
                }
                if (i + 1 >= k && is_palindrome[state << 1 & mask | t]) {
                    continue;
                }
                add(f[i + 1][state << 1 & mask | t], f[i][state]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= mask; i++) {
        add(ans, f[n][i]);
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