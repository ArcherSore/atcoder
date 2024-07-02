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

const int N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> v(2 * N);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x]++;
    }
    for (int i = 1; i <= 2 * N; i++) {
        v[i] = v[i - 1] + v[i];
    }

    LL ans = 0;
    for (int i = 1; i <= N; i++) {
        int num = v[i] - v[i - 1];
        if (num == 0) {
            continue;
        }
        for (int j = 1; i * j <= N; j++) {
            if (j == 1) {
                ans += 1LL * num * (v[i * j + i - 1] - v[i * j - 1] - num) * j;
            } else {
                ans += 1LL * num * (v[i * j + i - 1] - v[i * j - 1]) * j;
            }
        }
        ans += 1LL * num * (num - 1) / 2;
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