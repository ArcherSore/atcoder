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
    queue<int> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        q.push(x);
    }
    int time = 0;
    while (!q.empty()) {
        int fir = q.front();
        q.pop();
        if (time >= fir) {
            time += t;
        } else {
            time = fir + t;
        }
        cout << time << '\n';
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