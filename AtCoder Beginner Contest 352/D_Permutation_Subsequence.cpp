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
    int n, k;
    cin >> n >> k;
    vector<PII> a;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(a.begin(), a.end());
    a.push_back({0, 0});

    set<int> maxx, minn;
    for (int i = 0; i < k; i++) {
        minn.insert(a[i].second);
        maxx.insert(-a[i].second);
    }
    int res = 1e9;
    for (int i = 0; i < n - k + 1; i++) {
        res = min(res, -*maxx.begin() - *minn.begin());
        maxx.erase(-a[i].second), maxx.insert(-a[i + k].second);
        minn.erase(a[i].second), minn.insert(a[i + k].second);
    }
    cout << res;
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