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

vector<vector<char>> v(800, vector<char> (800));

void output(int i, int j, int n) {
    if (n == 0) {
        v[i][j] = '#';
        return;
    }
    int div = pow(3, n - 1);
    output(i, j, n - 1);
    output(i, j + div, n - 1);
    output(i, j + 2 * div, n - 1);
    output(i + div, j, n - 1);
    for (int p = i + div; p < i + 2 * div; p++) {
        for (int q = j + div; q < j + 2 * div; q++) {
            v[p][q] = '.';
        }
    }
    output(i + div, j + 2 * div, n - 1);
    output(i + 2 * div, j, n - 1);
    output(i + 2 * div, j + div, n - 1);
    output(i + 2 * div, j + 2 * div, n - 1);
}

void solve() {
    int n;
    cin >> n;
    output(1, 1, n);
    for (int i = 1; i <= (int)pow(3, n); i++) {
        for (int j = 1; j <= (int)pow(3, n); j++) {
            cout << v[i][j];
        }
        cout << '\n';
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