#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <iomanip>
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

LL n, a, x, y;
map<LL, double> memo;

double cal(LL t) {
    if (t == 0) {
        return 0;
    }
    if (memo.find(t) != memo.end()) {
        return memo[t];
    }
    double res1 = x + cal(t / a);
    double res2 = 1.2 * y;
    for (int i = 2; i <= 6; i++) {
        res2 += cal(t / i) / 5;
    }

    return memo[t] = min(res1, res2);
} 

void solve() {
    cin >> n >> a >> x >> y;
    cout << setprecision(16) << cal(n) << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}