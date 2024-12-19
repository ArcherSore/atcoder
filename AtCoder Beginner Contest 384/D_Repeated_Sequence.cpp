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
    int n;
    LL s;
    cin >> n >> s;

    LL sum = 0;
    vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    s %= sum;
    // cout << s << '\n';
    
    sum = 0;
    queue<LL> q;
    for (int i = 0; i < 2 * n; i++) {
        q.push(v[i % n]);
        sum += v[i % n];

        while (sum > s) {
            sum -= q.front();
            q.pop();
        }

        if (sum == s) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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