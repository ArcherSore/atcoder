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

struct DSU {
    vector<int> f, sizA, sizB;

    DSU() {}
    DSU(int n, vector<int> &A, vector<int> &B) {
        init(n, A, B);
    }

    void init(int n, vector<int> &A, vector<int> &B) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        sizA.assign(n, 0);
        sizB.assign(n, 0);
        for (int a : A) {
            sizA[a]++;
        }
        for (int b : B) {
            sizB[b]++;
        }
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        sizA[x] += sizA[y];
        sizB[x] += sizB[y];
        f[y] = x;
        return true;
    }

    int sizeA(int x) {
        return sizA[find(x)];
    }

    int sizeB(int x) {
        return sizB[find(x)];
    }

    void rmA(int x, int c) {
        x = find(x);
        sizA[x] = max(0, sizA[x] - c);
    }

    void rmB(int x, int c) {
        x = find(x);
        sizB[x] = max(0, sizB[x] - c);
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--, e.v--;
        edges[i] = e;
    }
    sort(edges.begin(), edges.end());

    vector<int> A(k), B(k);
    for (int i = 0; i < k; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < k; i++) {
        cin >> B[i];
        B[i]--;
    }

    DSU dsu(n, A, B);
    LL sum = 0;
    for (auto [u, v, w] : edges) {
        if (dsu.same(u, v)) {
            continue;
        }
        dsu.merge(u, v);
        int sA = max(dsu.sizeA(u), dsu.sizeA(v));
        int sB = max(dsu.sizeB(u), dsu.sizeB(v));
        sum += 1LL * min(sA, sB) * w;
        dsu.rmA(u, min(sA, sB));
        dsu.rmB(u, min(sA, sB));
    }
    cout << sum << '\n';
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