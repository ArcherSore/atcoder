#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 2e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, LL>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    LL res = INF;
    int path = 1;
    auto dfs = [&](auto &self, int cur, LL cost) -> void {
        if (cur == n - 1) {
            res = min(res, cost);
            return;
        }
        for (auto [v, w] : adj[cur]) {
            if ((path >> v) & 1) {
                continue;
            }
            path |= (1 << v);
            self(self, v, cost ^ w);
            path ^= (1 << v);
        }
    };
    dfs(dfs, 0, 0);

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