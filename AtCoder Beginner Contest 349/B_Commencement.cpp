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
    vector<int> num(256);
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        num[s[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (num[c] == i) {
                cnt++;
            }
        }
        if (cnt && cnt != 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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