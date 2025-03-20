#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 2e9;

void solve() {
    LL n, x;
    cin >> n >> x;
    vector<LL> u(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> d[i];
    }
    
    LL le = 0, ri = INF, mid;
    LL h = -1;
    auto check = [&]() -> bool {
        LL l = max(0LL, mid - d[0]), r = u[0];
        if (l > r) {
            return false;
        }
        for (int i = 1; i < n; i++) {
            l = max(l - x, max(0LL, mid - d[i]));
            r = min(r + x, u[i]);
            if (l > r) {
                return false;
            }
        }
        return true;
    };
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (check()) {
            h = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }

    LL res = 0;
    for (int i = 0; i < n; i++) {
        res += u[i] + d[i];
    }
    res -= n * h;
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