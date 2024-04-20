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
    int n, q;
    cin >> n >> q;
    vector<LL> sum(q + 1), a(n + 1), appear(n + 1);
    set<int> s;
    for (int i = 1, x; i <= q; i++) {
        cin >> x;
        if (s.find(x) != s.end()) {
            s.erase(x);
            a[x] += sum[i - 1] - sum[appear[x] - 1];
            appear[x] = 0;
        } else {
            s.insert(x);
            if (appear[x] == 0) {
                appear[x] = i;
            }
        }
        sum[i] = sum[i - 1] + (int)s.size();
    }
    for (auto x : s) {
        a[x] += sum[q] - sum[appear[x] - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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