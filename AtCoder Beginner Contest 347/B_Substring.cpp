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
    string s;
    cin >> s;
    set<string> ss;
    for (int i = 0; i < s.size(); i++) {
        for (int len = 1; i + len <= s.size(); len++) {
            string t = s.substr(i, len);
            // cout << t << '\n';
            ss.insert(t);
        }
    }
    cout << ss.size();
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