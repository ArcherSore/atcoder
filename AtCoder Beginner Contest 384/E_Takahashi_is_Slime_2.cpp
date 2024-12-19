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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Cell {
    int x, y;
    LL val;
    bool operator<(const Cell &other) const {
        return other.val < val;
    }
};

void solve() {
    int n, m;
    LL x;
    cin >> n >> m >> x;
    int sx, sy;
    cin >> sx >> sy;
    sx--, sy--;
    vector<vector<LL>> grid(n, vector<LL> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    LL sum = grid[sx][sy];
    priority_queue<Cell> q;
    vector<vector<bool>> vis(n, vector<bool> (m));
    vis[sx][sy] = true;
    for (int i = 0; i < 4; i++) {
        int xx = sx + dx[i];
        int yy = sy + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            q.push({xx, yy, grid[xx][yy]});
        }
    }
    while (!q.empty()) {
        auto [tx, ty, val] = q.top();
        q.pop();

        if (vis[tx][ty]) {
            continue;
        }
        vis[tx][ty] = 1;
        if ((__int128)val * x >= (__int128)sum) {
            break;
        }

        sum += val;
        for (int i = 0; i < 4; i++) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                q.push({xx, yy, grid[xx][yy]});
            }
        }
    }
    cout << sum << '\n';
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