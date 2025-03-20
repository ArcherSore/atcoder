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

const LL N = 2e6;

vector<LL> pri;
bool not_prime[N + 10];

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res *= a;
        }
        a *= a;
        x >>= 1;
    }
    return res;
}

void pre() {
    for (LL i = 2; i <= N; i++) {
        if (!not_prime[i]) {
            pri.push_back(i);
        }
        for (LL pri_j : pri) {
            if (i * pri_j > N) {
                break;
            }
            not_prime[i * pri_j] = 1;
            if (i % pri_j == 0) {
                break;
            }
        }
    }
}


void solve() {
    LL n;
    cin >> n;

    pre();

    int cnt = 0;
    for (int x : pri) {
        if (fpow(x, 8) > n) {
            break;
        }
        cnt++;
    }

    for (int i = 0; i < pri.size(); i++) {
        if (fpow(pri[i], 2) > n) {
            break;
        }
        for (int j = i + 1; j < pri.size(); j++) {
            if (pri[i] * pri[j] > floor(sqrt(n))) {
                break;
            }
            cnt++;
        }
    }

    cout << cnt;
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