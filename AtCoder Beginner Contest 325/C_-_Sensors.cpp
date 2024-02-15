#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char a[MAXN][MAXN];
int vis[MAXN][MAXN] = {{0}};
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int i, int j) {
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (a[x][y] == '#' && !vis[x][y]) {
            vis[x][y] = 1;
            dfs(x, y);
        }
    }
    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (vis[i][j] || a[i][j] == '.')
                continue;
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}