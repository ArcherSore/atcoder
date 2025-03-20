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

    int sum = 0, tp = 0;
    for (int i = 0; i < n; i++) {
        int t, v;
        cin >> t >> v;
        if (!i) {
            sum += v;
        } else {
            if (t - tp > sum) {
                sum = 0;
            } else {
                sum -= (t - tp);
            }
            sum += v;
        }
        tp = t;
    }
    cout << sum << '\n';
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