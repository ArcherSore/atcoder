#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef long long LL;
const int MAXN = 2e5 + 5;

LL n, k;
LL x[MAXN], y[MAXN];

LL check(LL mid) {
    LL l = 1, r = n, step = 0;
    while (l < r) {
        if (x[r] - x[l] <= mid) break; // 剩下的全在矩形内部了，不用调整
        step += x[r] - x[l] - mid;
        l++, r--;
    }
    l = 1, r = n;
    while (l < r) {
        if (y[r] - y[l] <= mid) break;
        step += y[r] - y[l] - mid;
        l++, r--;
    }
    return step;
}

int main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    LL l = 0, r = 2e9, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid) <= k) {
            // 需要的最小次数<=k
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld", ans);
    return 0;
}