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

const int MAXN = 2e5 + 10;

vector<vector<int>> G(MAXN);
vector<int> vis(MAXN);
int n, m;

LL bfs(int st) {
    LL cnt = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        cnt += 1;
        for (int u : G[x]) {
            if (!vis[u]) {
                q.push(u);
            }
        }
    }
    return cnt * (cnt - 1) / 2;
}

void solve() {
    cin >> n >> m;
    for (LL i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res += bfs(i);
        }
    }
    cout << res - m << '\n';
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