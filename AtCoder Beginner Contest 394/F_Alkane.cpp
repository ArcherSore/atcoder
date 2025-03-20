#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int res = 0;
    vector<vector<int>> dp(n, vector<int> (2));
    vector<int> vis(n);
    auto dfs = [&](auto &self, int u) -> void {
        vis[u] = 1;
        vector<int> son;
        for (auto v : g[u]) {
            if (deg[v] >= 4 && !vis[v]) {
                self(self, v);
                son.push_back(dp[v][1]);
            }
        }
        sort(son.rbegin(), son.rend());
        dp[u][0] = dp[u][1] = 1;
        for (int i = 0; i < min((int)son.size(), 3); i++) {
            dp[u][1] += son[i];
        }
        for (int i = 0; i < min((int)son.size(), 4); i++) {
            dp[u][0] += son[i];
        }
        res = max(res, dp[u][0]);
    };
    for (int i = 0; i < n; i++) {
        if (deg[i] >= 4 && !vis[i]) {
            dfs(dfs, i);
        }
    }

    if (res == 0) {
        cout << -1 << '\n';
    } else {
        cout << 3 * res + 2 << '\n';
    }
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