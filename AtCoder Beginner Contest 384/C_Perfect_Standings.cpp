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
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    set<pair<int, string>> mp;


    string s;
    int tot = 0;;
    for (int i = 0; i < 2; i++) {
        if (i) {
            s.push_back('A');
            tot += a;
        }
        for (int j = 0; j < 2; j++) {
            if (j) {
                s.push_back('B');
                tot += b;
            }
            for (int k = 0; k < 2; k++) {
                if (k) {
                    s.push_back('C');
                    tot += c;
                }
                for (int p = 0; p < 2; p++) {
                    if (p) {
                        s.push_back('D');
                        tot += d;
                    }
                    for (int q = 0; q < 2; q++) {
                        if (q) {
                            s.push_back('E');
                            tot += e;
                        }
                        if (!s.empty()) {
                            mp.insert({-tot, s});
                        }
                        if (q) {
                            s.pop_back();
                            tot -= e;
                        }
                    }
                    if (p) {
                        s.pop_back();
                        tot -= d;
                    }
                }
                if (k) {
                    s.pop_back();
                    tot -= c;
                }
            }
            if (j) {
                s.pop_back();
                tot -= b;
            }
        }
        if (i) {
            s.pop_back();
            tot -= a;
        }
    }

    for (auto [tot, str] : mp) {
        cout << str << '\n';
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