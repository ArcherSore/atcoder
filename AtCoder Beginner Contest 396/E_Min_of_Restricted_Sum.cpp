#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int flag = 1;
    vector<int> vis(n), pre(n);
    vector<int> cb(n);
    auto dfs = [&](auto &self, int u) -> void {
        vis[u] = 1;
        cb.push_back(u);
        for (auto [v, w] : adj[u]) {
            if (vis[v]) {
                if (w != (pre[v] ^ pre[u])) {
                    flag = 0;
                    return;
                }
                continue;
            }
            pre[v] = pre[u] ^ w;
            self(self, v);
        }
    };

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        cb.clear();
        dfs(dfs, i);
        if (!flag) {
            cout << -1 << '\n';
            return;
        }

        int rt = 0;
        for (int k = 30; k >= 0; k--) {
            int cnt0 = 0, cnt1 = 0;
            for (auto u : cb) {
                if ((pre[u] >> k) & 1) {
                    cnt0++;
                } else {
                    cnt1++;
                }
            }
            if (cnt1 < cnt0) {
                rt |= (1 << k);
            }
        }
        for (auto u : cb) {
            ans[u] = rt ^ pre[u];
        }
    }

    for (auto x : ans) {
        cout << x << ' ';
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