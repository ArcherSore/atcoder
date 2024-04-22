#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

double dist(PII a, PII b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve() {
    int n;
    cin >> n;
    vector<PII> pos(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
        double dis = 0;
        int ind;
        for (int j = 0; j < n; j++) {
            if (dist(pos[i], pos[j]) > dis) {
                ind = j, dis = dist(pos[i], pos[j]);
            }
        }
        cout << ind + 1<< '\n';
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