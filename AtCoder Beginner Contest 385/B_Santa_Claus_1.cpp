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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<char>> g(n, vector<char> (m));
    vector<vector<int>> vis(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    string opt;
    cin >> opt;
    int cnt = (g[x][y] == '@' ? 1 : 0);
    vis[x][y] = 1;
    for (char op : opt) {
        if (op == 'U' && x - 1 >= 0 && g[x - 1][y] != '#') {
            x -= 1;
        }
        if (op == 'D' && x + 1 < n && g[x + 1][y] != '#') {
            x += 1;
        } 
        if (op == 'L' && y - 1 >= 0 && g[x][y - 1] != '#') {
            y -= 1;
        }
        if (op == 'R' && y + 1 < m && g[x][y + 1] != '#') {
            y += 1;
        }
        if (g[x][y] == '@' && !vis[x][y]) {
            cnt += 1;
        }
        vis[x][y] = 1;
    }
    cout << x + 1 << ' ' << y + 1 << ' ' << cnt << '\n';
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