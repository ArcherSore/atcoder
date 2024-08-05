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

int n, m;
string s[11];
vector<vector<int>> flag(11, vector<int> (11));

int cnt = 0, res = 1e9;

bool check() {
    for (int i = 0; i < m; i++) {
        if (flag[n][i] == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int lvl) {
    if (lvl > n) {
        if (check()) {
            res = min(res, cnt);
        }
        return;
    }
    
    // choose
    for (int i = 0; i < m; i++) {
        if (s[lvl][i] == 'o') {
            flag[lvl][i] = flag[lvl - 1][i] | 1;
        } else {
            flag[lvl][i] = flag[lvl - 1][i] | 0;
        }
    }
    cnt++;
    dfs(lvl + 1);
    for (int i = 0; i < m; i++) {
        if (s[lvl][i] == 'o') {
            flag[lvl][i] = flag[lvl - 1][i];
        } else {
            flag[lvl][i] = flag[lvl - 1][i];
        }
    }
    cnt--;
    // not choose

    dfs(lvl + 1);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    dfs(1);
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