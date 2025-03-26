#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (t.size() % 2 == 0) {
            if (s[i] == 'i') {
                t.push_back('i');
            } else {
                t.push_back('i');
                t.push_back('o');
            }
        } else {
            if (s[i] == 'o') {
                t.push_back('o');
            } else {
                t.push_back('o');
                t.push_back('i');
            }
        }
    }
    if (t.size() % 2) {
        t.push_back('o');
    }
    cout << t.size() - s.size();
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