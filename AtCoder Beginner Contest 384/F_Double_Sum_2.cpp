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
#include <unordered_map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<LL> d(30);
    for (int k = 0; k <= 25; k++) {
        unordered_map<int, LL> fre, sum;
        for (int i = 0; i < n; i++) {
            fre[v[i] % (1 << k)]++;
            sum[v[i] % (1 << k)] += v[i];

            int t = (-v[i]) % (1 << k);
            if (t) {
                t += (1 << k);
            }
            d[k] += fre[t] * v[i] + sum[t];
        }
    }

    LL tot = 0;
    for (int k = 0; k <= 25; k++) {
        tot += (d[k] - d[k + 1]) / (1 << k);
    }
    cout << tot << '\n';
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