#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    
    int res = INF;
    vector<int> exist(N + 1, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (exist[x] == -1) {
            exist[x] = i;
        } else {
            res = min(res, i - exist[x] + 1);
            exist[x] = i;
        }
    }
    cout << (res == INF ? -1 : res) << '\n';
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