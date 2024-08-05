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

int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    const int T = n * m;
    int sx, sy;
    cin >> sx >> sy;
    vector<vector<LL>> a(n + 1, vector<LL> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<vector<LL>>> f(T + 1, vector<vector<LL>> (n + 1, vector<LL> (m + 1, -1)));
    f[0][sx][sy] = 0;
    for (int t = 1; t <= min(T, k); t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int s = 0; s < 5; s++) {
                    int x = i + dx[s], y = j + dy[s];
                    if (x > n || x < 1 || y > m || y < 1 || f[t - 1][x][y] == -1) {
                        continue;
                    }
                    f[t][i][j] = max(f[t][i][j], f[t - 1][x][y] + a[i][j]);
                }
            }
        }
    }

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, f[min(T, k)][i][j] + a[i][j] * (k - min(T, k)));
        }
    }
    cout << ans << '\n';
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