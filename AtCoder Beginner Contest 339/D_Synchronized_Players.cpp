#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <numeric>
using namespace std;

typedef long long LL;

const int MAXN = 70;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int vis[MAXN][MAXN][MAXN][MAXN];
char s[MAXN][MAXN];

struct Person {
    int x, y;
    int step;
};

int main() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            s[i][j] = '#';
        }
    }
    int n;
    cin >> n;
    vector<pair<int, int>> init;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'P') {
                init.push_back({i, j});
                s[i][j] = '.';
            }
        }
    }

    queue<Person> q;
    for (auto [x, y] : init) {
        q.push({x, y, 0});
    }
    vis[init[0].first][init[0].second][init[1].first][init[1].second] = 1;
    while (!q.empty()) {
        int step = q.front().step;
        int x1 = q.front().x, y1 = q.front().y;
        q.pop();
        int x2 = q.front().x, y2 = q.front().y;
        q.pop();

        // cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << '\n';

        for (int i = 0; i < 4; i++) {
            int a = x1 + dx[i], b = y1 + dy[i];
            int c = x2 + dx[i], d = y2 + dy[i];

            if (s[a][b] == '#') {
                a = x1, b = y1;
            }
            if (s[c][d] == '#') {
                c = x2, d = y2;
            }

            if (s[a][b] == '#' && s[c][d] == '#' || vis[a][b][c][d]) {
                continue;
            }

            vis[a][b][c][d] = 1;
            
            if (a == c && b == d) {
                cout << step + 1 << '\n';
                return 0;
            }

            q.push({a, b, step + 1});
            q.push({c, d, step + 1});
        }
    }

    cout << -1 << '\n';
    return 0;
}