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
    LL n, k;
    cin >> n >> k;
    set<int> s;
    LL tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > k) {
            continue;
        }
        if (s.find(x) == s.end()) {
            s.insert(x);
            tot += x;
        }
    }
    cout << (1 + k) * k / 2 - tot << '\n';
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