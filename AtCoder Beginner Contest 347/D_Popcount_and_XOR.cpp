#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

string get_bit(LL c, LL &ones) {
    ones = 0;
    string digit;
    while (c) {
        digit += (c & 1) + '0';
        ones += c & 1;
        c >>= 1;
    }
    return digit;
}

void print(string &s) {
    LL res = 0;
    reverse(s.begin(), s.end());
    for (auto c : s) {
        res <<= 1;
        res |= c - '0';
    }
    cout << res << " ";
}

void solve() {
    LL a, b, c;
    cin >> a >> b >> c;
    LL k;
    string s = get_bit(c, k);
    // cout << s << '\n';
    if ((a - b + k) % 2) {
        cout << -1 << '\n';
        return;
    }
    LL x = (a - b + k) / 2;
    LL rest = a - x;
    if (x > a || x < k - b || k < x || x < 0) {
        cout << -1 << '\n';
        return;
    }
    
    string X, Y;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') {
            if (x) {
                X += '1', Y += '0';
                x -= 1;
            } else {
                X += '0', Y += '1';
            }
        } 
        if (s[i] == '0') {
            if (rest) {
                X += '1', Y += '1';
                rest -= 1;
            } else {
                X += '0', Y += '0';
            }
        }
    }
    while (rest) {
        X += '1', Y += '1';
        rest -= 1;
    }
    // cout << X << " " << Y << '\n';
    if (X.size() > 60) {
        cout << -1;
        return;
    }
    print(X), print(Y);
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