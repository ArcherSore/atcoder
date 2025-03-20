#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1), label(n + 1), index(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[i] = i;
        label[i] = i;
        index[i] = i;
    }
    while (q--) {
        int opt, a, b;
        cin >> opt;
        if (opt == 1) {
            cin >> a >> b;
            pos[a] = index[b];
        } else if (opt == 2) {
            cin >> a >> b;
            swap(label[index[a]], label[index[b]]);
            swap(index[a], index[b]);
        } else {
            cin >> a;
            cout << label[pos[a]] << '\n';
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