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

vector<int> x(500), y(500);


void init() {
    string s = "wbwbwwbwbwbw";
    string t;
    for (int i = 1; i <= 20; i++) {
        t += s;
    }
    t = " " + t;
    int n = t.size();
    for (int i = 1; i <= n; i++) {
        if (t[i] == 'w') {
            x[i] = x[i - 1] + 1;
            y[i] = y[i - 1];
        } else {
            x[i] = x[i - 1];
            y[i] = y[i - 1] + 1;
        }
    }
}

void solve() {
    init();
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 240; i++) {
        for (int j = 1; j <= 240; j++) {
            if (x[i] - x[j - 1] == a && y[i] - y[j - 1] == b) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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