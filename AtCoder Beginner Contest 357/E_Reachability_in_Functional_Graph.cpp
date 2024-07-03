// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    // 拓扑排序处理链，剩下没访问过的都是环
    int n;
    cin >> n;
    vector<int> v(n), indeg(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        indeg[v[i]]++;
    }

    LL ans = 0;
    vector<int> vis(n, -1), depth(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
        depth[i] = 1;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u] != -1) {
            continue;
        }
        indeg[v[u]]--;
        vis[u] = 0;
        ans += 1LL * depth[u];

        if (indeg[v[u]] == 0) {
            q.push(v[u]);
        }
        depth[v[u]] += depth[u];
    }
    // cout << "ans = " << ans << '\n';
    // 统计环的大小
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            int cnt = 0, u = i;
            cnt++;
            while (v[u] != i) {
                cnt++;
                u = v[u];
            }
            u = i;
            vis[u] = cnt;
            while (v[u] != i) {
                u = v[u];
                vis[u] = cnt;
            }
            ans += 1LL * cnt * cnt;
        }
    }
    // cout << "ans = " << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && vis[v[i]]) {
            ans += 1LL * depth[i] * vis[v[i]];
        }
    }
    cout << ans << '\n';
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