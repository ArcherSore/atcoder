#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < 100; i++) {
        st.push(0);
    }
    while (n--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            cin >> x;
            st.push(x);
        } else {
            cout << st.top() << '\n';
            st.pop();
        }
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