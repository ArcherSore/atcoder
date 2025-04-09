#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            res++;
        }
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