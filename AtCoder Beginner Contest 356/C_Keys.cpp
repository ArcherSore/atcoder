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

int n, m, k, ans = 0;
vector<int> state;

void dfs(int lvl, vector<vector<int>> &g) {
    if (lvl == n) {
        // if has k keys
        // int cnt = 0;
        // for (auto key : state) {
        //     if (key == 1) {
        //         cnt++;
        //     }
        // }
        // if (cnt < k) {
        //     return;
        // }
        // if meet all the condition
        for (int i = 0; i < m; i++) {
            int opt = g[i][0], cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (g[i][j] == 0) {
                    break;
                }
                if (state[g[i][j] - 1] == 1) {
                    cnt++;
                }
            }
            if (opt && cnt < k || !opt && cnt >= k) {
                return;
            }
        }
        ans++;
        // output
        // for (auto x : state) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        return;
    }

    state.push_back(1);
    dfs(lvl + 1, g);
    state.pop_back();
    state.push_back(0);
    dfs(lvl + 1, g);
    state.pop_back();
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> g(m, vector<int> (n + 1));
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            cin >> g[i][j];
        }
        char opt;
        cin >> opt;
        if (opt == 'o') {
            g[i][0] = 1;
        } else {
            g[i][0] = 0;
        }
    }

    dfs(0, g);

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