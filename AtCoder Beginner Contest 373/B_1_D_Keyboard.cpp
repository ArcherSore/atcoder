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
    map<char, int> mp;
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        mp[s[i]] = i;
    }

    int ans = 0, last;
    for (auto [c, p] : mp) {
        if (c == 'A') {
            last = p;
        } else {
            ans += abs(last - p);
            last = p;
        }
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