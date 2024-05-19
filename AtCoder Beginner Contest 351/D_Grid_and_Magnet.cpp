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

int n, m, res = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char grid[1010][1010];
int vis[1010][1010];
int vist[1010][1010];

bool isin(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool exist(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (isin(x + dx[i], y + dy[i]) && grid[x + dx[i]][y + dy[i]] == '#') {
            return true;
        } 
    }
    return false;
}

void bfs(int i, int j) {
    queue<PII> q;
    q.push({i, j});
    int cnt = 0;
    vector<PII> pos;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (vist[x][y]) {
            continue;
        }
        vis[x][y] = 1;
        vist[x][y] = 1;
        cnt += 1;
        pos.push_back({x, y});
        
        if (exist(x, y)) { // 周围有磁铁
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!isin(xx, yy) || grid[xx][yy] == '#') {
                continue;
            }
            q.push({xx, yy});
        }
    }
    res = max(res, cnt);
    for (auto [x, y] : pos) {
        vist[x][y] = 0;
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << vis[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '#' || vis[i][j]) {
                continue;
            }
            bfs(i, j);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}