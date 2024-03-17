#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;
using LL = long long;

int flag = 0;
int n, m, k;
int cell[100][100];
int vis[100];

bool can_place(int p, int q, int x, int y) {
    if (p + x - 1 >= n || q + y - 1 >= m) {
        return false;
    }
    for (int i = p; i < p + x; i++) {
        for (int j = q; j < q + y; j++) {
            if (cell[i][j]) {
                return false;
            }
        }
    }
    return true;
} 

void place(int p, int q, int x, int y) {
    for (int i = p; i < p + x; i++) {
        for (int j = q; j < q + y; j++) {
            cell[i][j] ^= 1;
        }
    }
}

void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cell[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void dfs(int cnt, vector<PII> &bricks) {
    // cout << cnt << '\n';
    // output();

    if (cnt == n * m) {
        cout << "Yes\n";
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cell[i][j]) {
                continue;
            }
            for (int t = 0; t < k; t++) {
                if (vis[t]) {
                    continue;
                }
                vis[t] = 1;
                int x = bricks[t].first, y = bricks[t].second;
                if (can_place(i, j, x, y)) {
                    place(i, j, x, y);
                    dfs(cnt + x * y, bricks);
                    place(i, j, x, y);
                }
                if (x != y && can_place(i, j, y, x)) {
                    place(i, j, y, x);
                    dfs(cnt + x * y, bricks);
                    place(i, j, y, x);
                }
                vis[t] = 0; 
            }
            return;
        }
    }
}

void solve() {
    cin >> k >> n >> m;
    vector<PII> bricks(k);
    for (int i = 0; i < k; i ++) {
        cin >> bricks[i].first >> bricks[i].second;
    }

    dfs(0, bricks);

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}