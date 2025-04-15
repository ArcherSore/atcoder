#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n;
    cin >> n;

    LL cnt = 0;
    for (LL a = 1; ; a++) {
        if ((1LL << a) > n) {
            break;
        }
        LL t = n / (1LL << a);
        // cout << t << ": ";

        LL le = 1, ri = 1e9, mid;
        LL res = 0;
        while (le <= ri) {
            mid = (le + ri) / 2;
            if (mid * mid <= t) {
                res = mid;
                le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }
        // cout << res << '\n';
        cnt += (res + 1) / 2;
    }

    cout << cnt;
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