#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

void solve() {
    LL n;
    cin >> n;
    for (LL a = 1; a <= 1000000; a++) {
        if (n % a) {
            continue;
        }
        LL b = n / a;
        if (a * a >= b) {
            break;
        }
        ULL delta = 12 * b - 3 * a * a;
        LL sq_del = sqrtl(delta);
        if (sq_del == -1) {
            continue;
        }
        if (sq_del * sq_del == delta && sq_del >= 3 * a && (sq_del - 3 * a) % 6 == 0) {
            LL y = (sq_del - 3 * a) / 6;
            LL x = y + a;
            cout << x << ' ' << y;
            return;
        }
    }
    cout << -1;
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