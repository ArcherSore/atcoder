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
#define SZ(X) ((int)(X).size())

vector<int> pos[26];

void init(string &s) {
    for (int i = 0; i < s.size(); i++) {
        pos[s[i] - 'a'].push_back(i);
    }
}

bool check(LL n, string &s, string &T, LL mid) {
    long long t = 0;
    int p = 0;
    for(char c: T) {
        int v = c - 'a';
        long long need = mid;
        if(p > pos[v][0]) {
            int it = lower_bound(pos[v].begin(), pos[v].end(), p) - pos[v].begin();
            if(need + it > SZ(pos[v])) {
                need -= SZ(pos[v]) - it;
                t++;
                p = 0;
            } else {
                p = pos[v][it + need - 1] + 1;
                continue;
            }
        }
        if(need % SZ(pos[v])) {
            t += need / SZ(pos[v]);
            p = pos[v][need % SZ(pos[v]) - 1] + 1;
        } else {
            t += need / SZ(pos[v]) - 1;
            p = pos[v].back() + 1;
        }
        if(t > n) break;
    }

    return t < n;
}

void solve() {
    LL n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    init(s);

    for(char c: t) {
        if(!SZ(pos[c - 'a'])) {
            cout << "0\n";
            return;
        }
    }

    LL l = 0, r = SZ(s) * n / SZ(t), mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(n, s, t, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    // cout << check(n, t, 2) << '\n';

    cout << l << '\n';
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