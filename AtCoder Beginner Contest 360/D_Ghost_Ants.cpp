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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> p(n);
    vector<int> pos, neg;
    vector<int> pos_move,neg_move;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (s[i] == '1') {
            pos.push_back(p[i]);
            pos_move.push_back(p[i] + t);
        } else {
            neg.push_back(p[i]);
            neg_move.push_back(p[i] - t);
        }
    }

    sort(pos.begin(), pos.end());
    sort(pos_move.begin(), pos_move.end());
    sort(neg.begin(), neg.end());
    sort(neg_move.begin(), neg_move.end());

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int l = lower_bound(neg.begin(), neg.end(), p[i]) - neg.begin();
            int r = upper_bound(neg_move.begin(), neg_move.end(), p[i] + t) - neg_move.begin();
            ans += r - l;
        } else {
            int l = lower_bound(pos_move.begin(), pos_move.end(), p[i] - t) - pos_move.begin();
            int r = upper_bound(pos.begin(), pos.end(), p[i]) - pos.begin();
            ans += r - l;
        }
    }
    cout << ans / 2 << '\n';
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