#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    // Find the representative of the set containing x
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    // Check if x and y are in the same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    // Attach y's representative to x's representative
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    // Return the size of the set containing x.
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v, i + 1};
    }
    sort(edges.begin(), edges.end());

    int cnt = n;
    vector<vector<int>> adj(2 * n);
    vector<int> val(2 * n);
    DSU dsu(2 * n);
    for (auto &[u, v, w] : edges) {
        if (!dsu.same(u, v)) {
            adj[cnt].push_back(dsu.find(u));
            adj[cnt].push_back(dsu.find(v));
            dsu.merge(cnt, u);
            dsu.merge(cnt, v);
            val[cnt] = w;
            cnt++;
        }
    }
    adj.resize(cnt), val.resize(cnt);

    const int LOG = __lg(cnt) + 1;
    vector<vector<int>> parent(LOG, vector<int> (cnt, -1));
    vector<int> leaf(cnt); // the leaf count in the subtree of node u
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        parent[0][u] = fa;
        if (adj[u].empty()) {
            leaf[u] = 1;
            return;
        }
        for (int v : adj[u]) {
            self(self, v, u);
            leaf[u] += leaf[v];
        }
    };
    dfs(dfs, cnt - 1, -1); // the graph is connected
    // binary lifting
    for (int k = 0; k < LOG - 1; k++) {
        for (int u = 0; u < cnt; u++) {
            if (parent[k][u] != -1) {
                parent[k + 1][u] = parent[k][parent[k][u]];
            } else {
                parent[k + 1][u] = -1;
            }
        }
    }
    auto work = [&](int u, int limit) -> int {
        for (int i = LOG - 1; i >= 0; i--) {
            int nu = parent[i][u];
            if (nu != -1 && val[nu] <= limit) {
                u = nu;
            }
        }
        return u;
    };

    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        // binary search
        int le = 1, ri = m, mid;
        int res = 0;
        auto check = [&](int mid) -> bool {
            int nx = work(x, mid);
            int ny = work(y, mid);
            if (nx != ny) {
                return (leaf[nx] + leaf[ny]) >= z;
            } else {
                return leaf[nx] >= z;
            }
        };
        while (le <= ri) {
            mid = (le + ri) / 2;
            if (check(mid)) {
                res = mid;
                ri = mid - 1;
            } else {
                le = mid + 1;
            }
        }
        cout << res << '\n';
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