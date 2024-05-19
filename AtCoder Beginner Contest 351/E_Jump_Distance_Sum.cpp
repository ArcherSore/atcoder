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
using PLL = pair<LL, LL>;

bool cmp1(PLL &a, PLL &b) {
    return a.first < b.first;
}

bool cmp2(PLL &a, PLL &b) {
    return a.second < b.second;
}

LL cal(vector<LL> t1, vector<LL> t2) {
    LL n1 = t1.size(), n2 = t2.size();
    LL res = 0;
    for (LL i = 0; i < n1; i++) {
        res += t1[i] * (i + 1) * (n1 - i);
    }
    for (LL i = 0; i < n2; i++) {
        res += t2[i] * (i + 1) * (n2 - i);
    }
    return res / 2;
}

void solve() {
    int n;
    cin >> n;
    vector<PLL> e1, e2;
    for (int i = 0; i < n; i++) {
        LL a, b;
        cin >> a >> b;
        LL x = a + b, y = a - b;
        if (x % 2) {
            e1.emplace_back(x, y);
        } else {
            e2.emplace_back(x, y);
        }
    }
    LL res = 0;
    vector<LL> t1, t2;
    sort(e1.begin(), e1.end(), cmp1);
    sort(e2.begin(), e2.end(), cmp1);
    for (int i = 1; i < e1.size(); i++) {
        t1.push_back(e1[i].first - e1[i - 1].first);
    }
    for (int i = 1; i < e2.size(); i++) {
        t2.push_back(e2[i].first - e2[i - 1].first);
    }
    res += cal(t1, t2);
    t1.clear(), t2.clear();

    sort(e1.begin(), e1.end(), cmp2);
    sort(e2.begin(), e2.end(), cmp2);
    for (int i = 1; i < e1.size(); i++) {
        t1.push_back(e1[i].second - e1[i - 1].second);
    }
    for (int i = 1; i < e2.size(); i++) {
        t2.push_back(e2[i].second - e2[i - 1].second);
    }
    res += cal(t1, t2);

    cout << res;
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