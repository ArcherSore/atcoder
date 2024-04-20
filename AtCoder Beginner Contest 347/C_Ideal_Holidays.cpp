#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        d.emplace_back(x % (a + b));
    }
    sort(d.begin(), d.end());
    d.emplace_back(d[0] + a + b);
    for (int i = 1; i < d.size(); i++) {
        if (d[i] - d[i - 1] > b) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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