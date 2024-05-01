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
    vector<int> t(n + 1);
    set<PII> a;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        a.insert({t[i], i}); 
    }
    vector<PII> res;
    while (!a.empty()) {
        auto [x, pos] = *a.begin();
        a.erase({x, pos});
        if (x == pos) {
            continue;
        }
        a.erase({t[x], x});
        res.push_back({x, pos});
        a.insert({t[x], pos});
        t[pos] = t[x], t[x] = x;
    }
    cout << res.size() << '\n';
    for (auto [a, b] : res) {
        cout << a << " " << b << '\n';
    }
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