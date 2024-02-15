#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;

const int INF = 2e5 + 1;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int row[n][3], col[m][3]; // o x .
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'o') {
                row[i][0]++;
                col[j][0]++;
            } else if (grid[i][j] == 'x') {
                row[i][1]++;
                col[j][1]++;
            } else {
                row[i][2]++;
                col[j][2]++;
            }
        }
    }

    // 行
    int opt = INF;
    for (int i = 0; i < n; i++) {
        if (m < row[i][1] + k) continue;

        map<char, int> num;
        queue<int> q;
        for (int j = 0 ; j < m; j++) {
            if ((int)q.size() < k) {
                q.push(grid[i][j]);
                num[grid[i][j]]++;
                continue;
            }
// ?
            if (num['x'] == 0) {
                opt = min(opt, num['.']);
            }
            num[q.front()]--;
            q.pop();
            num[grid[i][j]]++;
            q.push(grid[i][j]);
        }
        if (num['x'] == 0) {
            opt = min(opt, num['.']);
        }
    }
    // 列
    for (int j = 0; j < m; j++) {
        if (n < col[j][1] + k) continue;

        map<char, int> num;
        queue<int> q;
        for (int i = 0 ; i < n; i++) {
            if ((int)q.size() < k) {
                q.push(grid[i][j]);
                num[grid[i][j]]++;
                continue;
            }
// ?
            if (num['x'] == 0) {
                opt = min(opt, num['.']);
            }
            num[q.front()]--;
            q.pop();
            num[grid[i][j]]++;
            q.push(grid[i][j]);
        }
        if (num['x'] == 0) {
            opt = min(opt, num['.']);
        }
    }
    if (opt == INF) cout << -1;
    else cout << opt;
    return 0;
}