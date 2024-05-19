#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int N = 4e5 + 10;
int n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, LL c, vector<LL> &tr) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

LL query(int x, vector<LL> &tr) {
    LL sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += tr[i];
    }
    return sum;
}

void solve() {
    cin >> n;
    vector<LL> a(n + 1), b(n + 1); // a原数组，b离散后数组
    vector<LL> num(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<LL> x(a);
    // discrete
    sort(x.begin() + 1, x.end());
    int cnt = unique(x.begin() + 1, x.end()) - x.begin() - 1;
    for (int i = 1; i <= n; i++) {
        b[i] = lower_bound(x.begin() + 1, x.begin() + cnt, a[i]) - x.begin();
    }
    // 维护num和sum
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        // cout << a[i] << " " << query(b[i], num) << " " << query(b[i], sum) << '\n';
        res += a[i] * query(b[i], num) - query(b[i], sum);
        add(b[i], 1, num), add(b[i], a[i], sum);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}