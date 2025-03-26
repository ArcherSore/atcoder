#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n * k);
    vector<int> deg(n * k);
    for (int i = 1; i < n * k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int flag = 1;
    vector<int> siz(n * k, 1);
    auto dfs = [&](auto &self, int u, int fa) -> void {
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
        }
        if (siz[u] < k && deg[u] > 2 || siz[u] > k) {
            flag = 0;
            return;
        }
        if (siz[u] == k) {
            if (deg[u] > 3) {
                flag = 0;
                return;
            }
            siz[u] = 0;
            if (fa != -1) {
                deg[fa]--;
            }
        }
    };
    dfs(dfs, 0, -1);
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
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