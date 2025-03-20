#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    map<char, char> mp;
    mp['('] = ')';
    mp[')'] = '(';
    mp['['] = ']';
    mp[']'] = '[';
    mp['<'] = '>';
    mp['>'] = '<';

    string s;
    cin >> s;
    map<char, int> cnt;
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '<') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != mp[c]) {
                cout << "No\n";
                return;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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