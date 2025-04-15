#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s : g) {
        cin >> s;
    }
    vector<vector<PII>> adj(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                int xx = i + 2 * dx[k], yy = j + 2 * dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    continue;
                }
                if (g[x][y] == '.') {
                    adj[i * m + j].push_back({x * m + y, 0});
                } else {
                    adj[i * m + j].push_back({x * m + y, 1});
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
                        continue;
                    }
                    adj[i * m + j].push_back({xx * m + yy, 1});
                }
            }
        }
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    
    vector<int> vis(n * m);
    vector<int> dist(n * m, INF);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[a * m + b] = 0;
    pq.push({0, a * m + b});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;

        for (auto [v, dis] : adj[u]) {
            if (dist[v] > dist[u] + dis) {
                dist[v] = dist[u] + dis;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[c * m + d];
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