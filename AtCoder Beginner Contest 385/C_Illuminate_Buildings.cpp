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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int dif = 1; dif <= n; dif++) {
        vector<int> vis(n);
        int cur = 0, cnt = 0;
        while (cur < n) {
            cnt = 0;
            for (int i = cur; i < n; i += dif) {
                if (v[i] != v[cur]) {
                    break;
                }
                cnt += 1;
                vis[cur] = 1;
            }
            res = max(res, cnt);
            while (cur < n && vis[cur]) {
                cur += 1;
            }
        }   
    }
    cout << res << '\n';
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