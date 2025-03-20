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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Node {
    int x, y, step;
};

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    queue<Node> q;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'H') {
                q.push({i, j, 0});
            }
        }
    }

    int sum = 0;
    vector<vector<int>> vis(n, vector<int> (m));
    while (!q.empty()) {
        auto [x, y, step] = q.front();
        q.pop();
        if (vis[x][y] || step > d) {
            continue;
        }
        vis[x][y] = 1;

        if (g[x][y] == 'H' || g[x][y] == '.') {
            sum += 1;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || g[xx][yy] == '#') {
                continue;
            }
            q.push({xx, yy, step + 1});
        }
    }
    cout << sum;
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