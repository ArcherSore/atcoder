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
    int n, m, d;
    cin >> n >> m >> d;
    vector<PII> floor;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '.') {
                floor.push_back({i, j});
            }
        }
    }

    auto calc = [&](auto &self, PII x, PII y) -> int {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '#') {
                    continue;
                }
                if (abs(i - x.first) + abs(j - x.second) <= d || abs(i - y.first) + abs(j - y.second) <= d) {
                    sum += 1;
                }
            }
        }
        return sum;
    };

    int sum = 0;
    for (int i = 0; i < floor.size(); i++) {
        for (int j = i + 1; j < floor.size(); j++) {
            sum = max(sum, calc(calc, floor[i], floor[j]));
        }
    }

    cout << sum;
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