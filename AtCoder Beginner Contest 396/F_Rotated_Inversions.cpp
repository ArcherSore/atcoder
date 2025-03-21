#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] < k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<vector<int>> p(m);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        v[i] = x;
        p[x].push_back(i);
    }

    Fenwick<LL> a(m);
    LL cnt = 0;
    for (int i = n; i > 0; i--) {
        cnt += a.sum(v[i]);
        a.add(v[i], 1);
    }

    vector<LL> res = {cnt};
    for (int i = m - 1; i > 0; i--) {
        int k = p[i].size();
        for (int j = 0; j < k; j++) {
            cnt -= n - p[i][j] - (k - j - 1);
        }
        for (int j = 0; j < k; j++) {
            cnt += p[i][j] - j - 1;
        }
        res.push_back(cnt);
    }

    for (auto x : res) {
        cout << x << '\n';
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