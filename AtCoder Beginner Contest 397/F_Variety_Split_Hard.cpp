#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};

struct Tag {
    int add = 0;
    Tag() {}
    Tag(int x) : add(x) {} 
    void apply(const Tag &t) & {
        add += t.add;
    }
};

struct Info {
    int mx = 0;
    Info() {}
    Info(int x) : mx(x) {}
    void apply(const Tag &t) & {
        mx += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.mx, b.mx)};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> vis(n + 1);
    vector<int> pre(n), suf(n);
    pre[0] = vis[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (1 - vis[a[i]]);
        vis[a[i]] = 1;
    }
    vis.assign(n + 1, 0);
    suf[n - 1] = vis[a[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (1 - vis[a[i]]);
        vis[a[i]] = 1;
    }

    vector<int> last(n + 1, -1);
    LazySegmentTree<Info, Tag> seg(n);
    last[a[0]] = 0;
    seg.modify(0, Info(1));
    int res = 0;
    for (int j = 1; j < n - 1; j++) {
        seg.modify(j, Info(pre[j - 1] + 1));

        int p = last[a[j]];
        seg.rangeApply(p + 1, j, Tag(1));
        last[a[j]] = j;

        res = max(res, seg.rangeQuery(p + 1, j + 1).mx + suf[j + 1]);
    }
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