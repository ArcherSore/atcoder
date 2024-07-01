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
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
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
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<DSU> dsu(11, DSU(n + 1));
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = c; j <= 10; j++) {
            dsu[j].merge(a, b);
        }
        ans += c;
    }

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = c; i <= 10; i++) {
            if (dsu[i].find(a) == dsu[i].find(b)) {
                ans -= max(i - c, 0);
                break;
            }
            dsu[i].merge(a, b);
        }
        cout << ans << '\n';
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