#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        vector<int> d;
        for (auto v : adj[i]) {
            d.push_back(deg[v]);
        }
        sort(d.begin(), d.end(), greater<>());
        for (int x = 0; x < deg[i]; x++) {
            res = max(res, 1 + (x + 1) + (x + 1) * (d[x] - 1));
        }
    }
    cout << n - res << '\n';
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