#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    vector<int> app(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        v[i] -= 1;
        app[v[i]] = i;
    }
    int res = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (i == app[v[i]] || i - 1 == app[v[i - 1]]) {
            continue;
        }
        if (v[i] != v[i - 1] && abs(app[v[i - 1]] - app[v[i]]) == 1 && i + 1 != app[v[i]]) {
            res++;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}