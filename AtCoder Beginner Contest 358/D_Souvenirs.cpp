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
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> st;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        st.push(x);
    }

    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    LL ans = 0;
    for (int i = 0; i < m; i++) {
        while (!st.empty() && st.top() < v[i]) {
            st.pop();
        }
        if (st.empty()) {
            cout << -1 << '\n';
            return;
        }
        ans += 1LL * st.top();
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