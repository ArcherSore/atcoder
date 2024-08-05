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

int n, m, k;

int dist(int x, int y) {
    return abs(x - n) + abs(y - m);
}

void fill_route(vector<PII> &route) {
    int num = route.size();
    if (route[num - 1].first == route[num - 2].first) {
        for (int i = route.back().first + 1; i <= n; i++) {
            route.push_back({i, route.back().second});
        }
        for (int j = route.back().second + 1; j <= m; j++) {
            route.push_back({route.back().first, j});
        }
    } else {
        for (int j = route.back().second + 1; j <= m; j++) {
            route.push_back({route.back().first, j});
        }
        for (int i = route.back().first + 1; i <= n; i++) {
            route.push_back({i, route.back().second});
        }
    }
}

vector<PII> walk_even() {
    vector<PII> route;
    int step = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            for (int j = m; j >= 1; j--) {
                route.push_back({i, j});
                step += 1;
                if (step + dist(i, j) == k) {
                    fill_route(route);
                    return route;
                }
            }
        } else {
            for (int j = 1; j <= m; j++) {
                route.push_back({i, j});
                step += 1;
                if (step + dist(i, j) == k) {
                    return route;
                }
            }
        }
    }
    return route;
}

vector<PII> walk_odd() {
    vector<PII> route;
    if (k == 1) {
        route.push_back({1, m});
        return route;
    }
    int step = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (i % 2) {
            for (int j = m; j >= 1; j--) {
                route.push_back({i, j});
                step += 1;
                if (step + dist(i, j) == k) {
                    fill_route(route);
                    return route;
                }
            }
        } else {
            for (int j = 1; j <= m; j++) {
                route.push_back({i, j});
                step += 1;
                if (step + dist(i, j) == k) {
                    fill_route(route);
                    return route;
                }
            }
        }
    }
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, 1};
    int x = n - 1, y = 1;
    for (int i = 0; ; i++) {
        route.push_back({x, y});
        step += 1;
        if (step + dist(x, y) == k) {
            fill_route(route);
            return route;
        }
        x += dx[i % 4], y += dy[i % 4];
    }
    return route;
}

void draw(vector<PII> &route) {
    vector<vector<char>> ans(2 * n + 2, vector<char> (2 * m + 2, '?'));
    // border
    for (int j = 1; j <= 2 * m + 1; j++) {
        ans[1][j] = ans[2 * n + 1][j] = '+';
    }
    ans[1][2 * m] = 'S';
    ans[2 * n + 1][2 * m] = 'G';
    for (int i = 2; i <= 2 * n; i++) {
        if (i % 2) {
            for (int j = 1; j <= 2 * m + 1; j += 2) {
                ans[i][j] = '+';
            }
        } else {
            ans[i][1] = ans[i][2 * m + 1] = '+';
        }
    }
    // cell
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[2 * i][2 * j] = 'o';
        }
    }
    // passage
    for (int i = 0; i < route.size(); i++) {
        int x = route[i].first, y = route[i].second;
        if (i) {
            int xx = route[i - 1].first, yy = route[i - 1].second;
            ans[x + xx][y + yy] = '.';
        }
    }
    // wall
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2 * m + 1; j++) {
            if (ans[i][j] != '?') {
                continue;
            }
            if (i % 2) {
                ans[i][j] = '-';
            } else {
                ans[i][j] = '|';
            }
        }
    }
    // output
    cout << "Yes\n";
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2 * m + 1; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

void solve() {
    cin >> n >> m >> k;
    if (k % 2 != n % 2 || k < n || k > n * m) {
        cout << "No\n";
        return;
    }

    vector<PII> route;
    if (n % 2 == 0) {
        route = walk_even();
    } else {
        route = walk_odd();
    }

    // for (auto [x, y] : route) {
    //     cout << x << ' ' << y <<  '\n';
    // }

    draw(route);
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