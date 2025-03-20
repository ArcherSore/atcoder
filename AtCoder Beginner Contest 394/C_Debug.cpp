#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        int p = i;
        while (p >= 0 && s[p] == 'W' && s[p + 1] == 'A') {
            s[p] = 'A', s[p + 1] = 'C';
            p--;
        }
    }
    cout << s << '\n';
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