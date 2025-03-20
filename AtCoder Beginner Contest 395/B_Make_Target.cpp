#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char> (n));
    for (int k = 0; k <= n / 2; k++) {
        char c;
        if (k % 2) {
            c = '.';
        } else {
            c = '#';
        }
        for (int j = k; j < n - k; j++) {
            g[k][j] = c;
            g[n - k - 1][j] = c;
        }
        for (int i = k + 1; i < n - k - 1; i++) {
            g[i][k] = c;
            g[i][n - k - 1] = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << '\n';
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