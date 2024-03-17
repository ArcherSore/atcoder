#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;
using LL = long long;

void solve() {
    LL x;
    cin >> x;
    if (x % 10 == 0) {
        cout << x / 10;
    } else {
        if (x > 0) {
            cout << x / 10 + 1;
        } else {
            cout << x / 10;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}