#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> pre, suf;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
        suf[x]++;
    }
    int res = suf.size();
    for (int i = 0; i < n; i++) {
        pre[v[i]]++;
        suf[v[i]]--;
        if (suf[v[i]] == 0) {
            suf.erase(v[i]);
        }
        res = max((size_t)res, pre.size() + suf.size());
    }
    cout << res;
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