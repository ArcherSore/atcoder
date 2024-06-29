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

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> x(4), y(4);
    vector<vector<int>> s = {{0, 1, 0, 1}, {1, 2, 1, 2}, {2, 1, 2, 1}, {1, 0, 1, 0}};

    for (int i = 0; i < 4; i++) {
        double l, r;
        l = 1.0 * (x1 - i) / 4, r = 1.0 * (x2 - i) / 4;
        x[i] = floor(r) - floor(l);
    }

    for (int i = 0; i < 4; i++) {
        double l, r;
        l = 1.0 * (y1 - i) / 4, r = 1.0 * (y2 - i) / 4;
        y[i] = floor(r) - floor(l);
    }
    
    LL area = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // cout << 1LL * x[i] * y[j] * s[i][j] << '\n';
            area += 1LL * x[i] * y[j] * s[i][j];
        }
    }

    cout << area << '\n';
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