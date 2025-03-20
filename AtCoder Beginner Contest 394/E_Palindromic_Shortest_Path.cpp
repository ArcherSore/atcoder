#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> c(n, vector<char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    vector<vector<int>> a(n, vector<int> (n, INF));
    queue<PII> q;
    for (int i = 0; i < n; i++) {
        a[i][i] = 0;
        q.push({i, i});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && c[i][j] != '-') {
                a[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][u] == c[v][j] && c[i][u] !=  '-' && a[i][j] > a[u][v] + 2) {
                    a[i][j] = a[u][v] + 2;
                    q.push({i, j});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (a[i][j] == INF ? -1 : a[i][j]) << ' ';
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