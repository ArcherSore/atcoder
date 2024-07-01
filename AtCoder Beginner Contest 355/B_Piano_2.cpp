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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> v;
    int p1 = 0, p2 = 0;
    while (p1 != n && p2 != m) {
        if (a[p1] < b[p2]) {
            if (!v.empty() && v.back() == 1) {
                cout << "Yes";
                return;
            }
            v.push_back(1);
            p1++;
        } else {
            v.push_back(2);
            p2++;
        }
    }
    while (p1 != n) {
        if (!v.empty() && v.back() == 1) {
            cout << "Yes";
            return;
        }
        v.push_back(1);
        p1++;
    }
    cout << "No";
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