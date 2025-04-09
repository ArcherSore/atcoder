#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> scr(101);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        scr[x].push_back(i);
    }
    vector<int> res(n);
    int rk = 1;
    for (int i = 100; i >= 1; i--) {
        for (auto x : scr[i]) {
            res[x] = rk;
        }
        rk += scr[i].size();
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