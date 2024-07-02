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
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<int> t(m);
    for (int i = 0; i < n; i++) {
        int x;
        for (int j = 0; j < m; j++) {
            cin >> x;
            t[j] += x;
        }
    }

    for (int i = 0; i < m; i++) {
        if (t[i] < a[i]) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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