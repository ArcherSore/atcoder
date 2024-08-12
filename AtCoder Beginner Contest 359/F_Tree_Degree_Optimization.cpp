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

struct Cost {
    LL cost, mul;
    bool operator<(const Cost &other) const {
        return cost / mul / mul * (mul + 1) * (mul + 1) - cost > other.cost / other.mul / other.mul * (other.mul + 1) * (other.mul + 1) - other.cost;
    }
};

void solve() {
    int n;
    cin >> n;
    priority_queue<Cost> st;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        st.push({x, 1LL});
    }

    int opt = n - 2;
    while (opt--) {
        LL t = st.top().cost, c = st.top().mul;
        st.pop();
        st.push({t / (c * c) * ((c + 1) * (c + 1)), c + 1});
    }

    LL ans = 0;
    while (!st.empty()) {
        ans += st.top().cost;
        st.pop();
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