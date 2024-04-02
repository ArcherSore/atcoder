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

struct Opt {
    int t, a, x;
};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<Opt> opt(w);
    for (int i = 0; i < w; i++) {
        cin >> opt[i].t >> opt[i].a >> opt[i].x;
    }

    vector<LL> res(2e5 + 10);
    res[0] = 1LL * n * m;
    set<int> col, row;
    for (int i = w - 1; i >= 0; i--) {
        int t, a, x;
        t = opt[i].t, a = opt[i].a, x = opt[i].x;
        if (t == 1) {
            if (row.count(a)) {
                continue;
            }
            int num = m - col.size();
            res[0] -= num;
            res[x] += num;
            row.insert(a);
        } else {
            if (col.count(a)) {
                continue;
            }
            int num = n - row.size();
            res[0] -= num;
            res[x] += num;
            col.insert(a);
        }
    }

    int cnt = 0;
    vector<pair<int, LL>> ans;
    for (int i = 0; i <= 2e5; i++) {
        if (res[i] > 0) {
            cnt++;
            ans.push_back({i, res[i]});
        }
    }

    cout << cnt << '\n';
    for (auto [col, num] : ans) {
        cout << col << " " << num << '\n';
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