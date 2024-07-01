// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> row(n + 1), col(n + 1);
    int ldig = 0, rdig = 0;

    int res = -1;
    for (int i = 0, a; i < t; i++) {
        cin >> a;
        int x = (a - 1) / n + 1, y = (a - 1) % n + 1;
        row[x]++, col[y]++;
        if (x == y) {
            ldig++;
        }
        if (x + y == n + 1) {
            rdig++;
        }

        if (res == -1 && (row[x] == n || col[y] == n || ldig == n || rdig == n)) {
            res = i + 1;
        }
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