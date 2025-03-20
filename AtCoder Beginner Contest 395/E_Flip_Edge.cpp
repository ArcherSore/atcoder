#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e18;

struct State {
    int u;
    LL cost;
    int inv;
    bool operator>(const State &ohter) const {
        return cost > ohter.cost;
    }
};

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<PII>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 0});
    vector<vector<bool>> vis(n, vector<bool> (2, false));
    vector<vector<LL>> dist(n, vector<LL> (2, INF));
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto [u, cost, inv] = pq.top();
        pq.pop();
        if (vis[u][inv]) {
            continue;
        }
        vis[u][inv] = true;

        for (auto [v, dir] : adj[u]) {
            if (dir == inv) {
                if (dist[v][dir] > cost + 1) {
                    dist[v][dir] = cost + 1;
                    pq.push({v, dist[v][dir], dir});
                }
            } else {
                if (dist[v][dir] > cost + x + 1) {
                    dist[v][dir] = cost + x + 1;
                    pq.push({v, dist[v][dir], dir});
                }
            }
        }
    }
    cout << min(dist[n - 1][0], dist[n - 1][1]) << '\n';
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