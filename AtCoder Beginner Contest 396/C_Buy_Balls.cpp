#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int p1 = 0, p2 = 0;

    LL res = 0;
    while (a[p1] > 0) {
        res += a[p1];
        p1++;
    }
    while (p2 < p1 && b[p2] > 0) {
        res += b[p2];
        p2++;
    }
    while (p1 < n && p2 < m && a[p1] + b[p2] > 0) {
        res += a[p1] + b[p2];
        p1++, p2++;
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