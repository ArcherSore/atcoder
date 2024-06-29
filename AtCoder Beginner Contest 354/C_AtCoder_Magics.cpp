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

struct Card {
    int a, c;
    int id;
    bool operator<(const Card &other) const {
        if (other.a != a) {
            return a > other.a;
        } else {
            return c > other.c;
        }
    }
};

void solve() {
    int n;
    cin >> n;   
    vector<Card> v(n);
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        v[i] = {a, c, i + 1};
    }
    sort(v.begin(), v.end());

    // for (auto [a, c, id] : v) {
    //     cout << a << " " << c << " " << id << '\n';
    // }

    int pre = 0;
    vector<int> res = {v[0].id};
    for (int i = 1; i < n; i++) {
        if (v[i].a < v[pre].a && v[i].c < v[pre].c) {
            res.push_back(v[i].id);
            pre = i;
        }
    }
    
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for (auto r : res) {
        cout << r << " ";
    }
    cout << '\n';
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