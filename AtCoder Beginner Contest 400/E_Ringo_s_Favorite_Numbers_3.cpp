#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 5e5;
const int INF = 1e6;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    vector<LL> pri = {2, 3};
    for (int i = 5; i <= N; i++) {
        if (is_prime(i)) {
            pri.push_back(i);
        }
    }
    vector<pair<LL, LL>> tot;
    for (auto x : pri) {
        LL y = x;
        while (x < INF) {
            tot.push_back({x, y});
            x *= y;
        }
    }
    sort(tot.begin(), tot.end());

    vector<LL> res;
    for (int i = 0; i < tot.size(); i++) {
        LL ori1 = tot[i].second, cur1 = tot[i].first;
        for (int j = i + 1; j < tot.size(); j++) {
            LL ori2 = tot[j].second, cur2 = tot[j].first;
            if (ori1 == ori2) {
                continue;
            }
            if (cur1 * cur2 > INF) {
                break;
            }
            res.push_back(cur1 * cur2 * cur1 * cur2);
        }
    }
    sort(res.begin(), res.end());
    // cout << res.back() << '\n';
    
    int n;
    cin >> n;
    while (n--) {
        LL x;
        cin >> x;
        int p = upper_bound(res.begin(), res.end(), x) - res.begin() - 1;
        cout << res[p] << '\n';
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