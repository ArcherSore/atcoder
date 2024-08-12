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
using PLI = pair<LL, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    stack<PLI> seq;
    seq.push({v[1], 1});

    LL ans = v[1] + 1;
    cout << ans << ' ';
    for (int i = 2; i <= n; i++) {
        int cnt = 1;
        while (!seq.empty() && v[i] >= seq.top().first) {
            ans -= seq.top().first * seq.top().second;
            cnt += seq.top().second;
            
            seq.pop();
        }
        ans += v[i] * cnt;
        seq.push({v[i], cnt});

        cout << ans << ' ';
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