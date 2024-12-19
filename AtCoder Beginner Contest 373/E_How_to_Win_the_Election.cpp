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

bool check(LL x, LL Ai, const vector<LL> &sorted_A, LL m, LL add, vector<LL> &pre_sum_A, LL rest) {
    int p = lower_bound(sorted_A.begin(), sorted_A.end(), Ai, greater<> ()) - sorted_A.begin();
    int pp = lower_bound(sorted_A.begin(), sorted_A.end(), Ai + x + 1, greater<> ()) - sorted_A.begin();
    int n = sorted_A.size();
    if (p < m) {
        return (m - pp) * (Ai + x + 1) > (pre_sum_A[m - 1] - (pp == 0 ? 0 : pre_sum_A[pp - 1]) - Ai + add) + rest;
    } else {
        if (pp < m) {
            return (m - pp) * (Ai + x + 1) > pre_sum_A[m - 1] - (pp == 0 ? 0 : pre_sum_A[pp - 1]) + rest;
        } else {
            return false;
        }
    }
}

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> A(n);
    LL sum_A = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum_A += A[i];
    }
    vector<LL> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<> ());

    // 特判全不需要的情况
    if (n == m) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        return;
    }

    LL m_th = sorted_A[m - 1];
    for (int i = m; i < n; i++) {
        if (sorted_A[i] < sorted_A[m - 1]) {
            m_th = sorted_A[i];
            break;
        }
    }

    vector<LL> pre_sum_A(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre_sum_A[i] = sorted_A[i];
        } else {
            pre_sum_A[i] = sorted_A[i] + pre_sum_A[i - 1];
        }
    }
    
    for (int i = 0; i < n; i++) {
        LL l = 0, r = k - sum_A + 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (check(mid, A[i], sorted_A, m, m_th, pre_sum_A, k - sum_A - mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l > k - sum_A) {
            cout << -1 << ' ';
        } else {
            cout << l << ' ';
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