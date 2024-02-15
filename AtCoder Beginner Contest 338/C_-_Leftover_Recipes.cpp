#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

const int INF = 1e6 + 5;

bool check(vector<int> &Q, vector<int> &a, vector<int> &b, int x1, int x2, int n) {
    for (int i = 0; i < n; i++) {
        if (x1 * a[i] + x2 * b[i] > Q[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> Q(n), a(n), b(n);
    int max1 = INF, max2 = INF;
    for (int i = 0; i < n; i++) {
        cin >> Q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) continue;
        else {
            max1 = min(max1, Q[i] / a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 0) continue;
        else {
            max2 = min(max2, Q[i] / b[i]);
        }
    }
    //cout << max1 << " " << max2 << '\n';
    int ans = 0;
    for (int i = 0; i <= max1; i++) {
        int l = 0, r = max2, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (check(Q, a, b, i, mid, n)) l = mid;
            else r = mid - 1;
        }
        // printf("1 = %d, 2 = %d\n", i, l);
        ans = max(ans, i + l);
    }

    cout << ans << '\n';
    return 0;
}