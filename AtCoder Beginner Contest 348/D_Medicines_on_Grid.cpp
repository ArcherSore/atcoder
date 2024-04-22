#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int MAXN = 210;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int grid[MAXN][MAXN];
int vis[MAXN][MAXN]; // 记录的能量

struct Status {
    int x, y, e;
    bool operator>(const Status &other) const {
        return e < other.e;
    }
};

void solve() {
    memset(vis, -1, sizeof (vis));
    int h, w;
    cin >> h >> w;
    int sx, sy, tx, ty;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == '#' ? -1 : 0);
            if (c == 'S') {
                sx = i, sy = j;
            }
            if (c == 'T') {
                tx = i, ty = j;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if (grid[x][y] != -1) {
            grid[x][y] = c;
        }
    }

    priority_queue<Status, vector<Status>, greater<Status>> q;
    q.push({sx, sy, grid[sx][sy]});
    while (!q.empty()) {
        auto [x, y, e] = q.top();
        q.pop();
        if (vis[x][y] >= e) {
            continue;
        }
        // cout << x << " " << y << " " << e << endl;
        vis[x][y] = e;

        if (x == tx && y == ty) {
            cout << "Yes";
            return; 
        }

        if (e < 1) {
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i], ee = e - 1;
            if (xx < 1 || xx > h || yy < 1 || yy > w || grid[xx][yy] == -1) {
                continue;
            }
            ee = max(ee, grid[xx][yy]);
            q.push({xx, yy, ee});
        }
    }

    cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("main.txt", "w", stdout);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}