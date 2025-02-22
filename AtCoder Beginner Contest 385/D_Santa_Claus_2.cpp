#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    LL sx, sy;
    cin >> n >> m >> sx >> sy;
    map<LL, set<LL>> mx, my;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mx[x].insert(y);
        my[y].insert(x);
    }
    int cnt = 0;
    if (mx.find(sx) != mx.end() && mx[sx].find(sy) != mx[sx].end()) {
        cnt++;
        mx[sx].erase(sy);
        mx[sy].erase(sx);
    }
    for (int i = 0; i < m; i++) {
        char dir;
        int c;
        cin >> dir >> c;
        if (dir == 'U') {
            // (sy, sy+c]
            if (mx.find(sx) != mx.end()) {
                auto l = mx[sx].lower_bound(sy + 1);
                auto r = mx[sx].upper_bound(sy + c);
                for (auto it = l; it != r; it++) {
                    cnt++;
                    my[*it].erase(sx);
                }
                mx[sx].erase(l, r);
            }
            sy += c;
        } else if (dir == 'D') {
            // [sy-c, sy)
            if (mx.find(sx) != mx.end()) {
                auto l = mx[sx].lower_bound(sy - c);
                auto r = mx[sx].upper_bound(sy - 1);
                for (auto it = l; it != r; it++) {
                    cnt++;
                    my[*it].erase(sx);
                }
                mx[sx].erase(l, r);
            }
            sy -= c;
        } else if (dir == 'R') {
            // (sx, sx+c]
            if (my.find(sy) != my.end()) {
                auto l = my[sy].lower_bound(sx + 1);
                auto r = my[sy].upper_bound(sx + c);
                for (auto it = l; it != r; it++) {
                    cnt++;
                    mx[*it].erase(sy);
                }
                my[sy].erase(l, r);
            }
            sx += c;
        } else {
            // [sx-c, sx)
            if (my.find(sy) != my.end()) {
                auto l = my[sy].lower_bound(sx - c);
                auto r = my[sy].upper_bound(sx - 1);
                for (auto it = l; it != r; it++) {
                    cnt++;
                    mx[*it].erase(sy);
                }
                my[sy].erase(l, r);
            }
            sx -= c;
        }
    }
    cout << sx << ' ' << sy << ' ' << cnt << '\n';
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