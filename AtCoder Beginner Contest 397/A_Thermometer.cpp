#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    double x;
    cin >> x;
    if (x >= 38.0) {
        cout << 1;
    } else if (x < 37.5) {
        cout << 3;
    } else {
        cout << 2;
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