#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(k + 2);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end() - 1);

    LL ans = 0;
    if (k % 2 == 0) {
        for (int i = 1; i <= k; i += 2) {
            ans += a[i + 1] - a[i];
        }
    } else {
        LL max_div = 0, max_ind = 1;
        a[0] = a[1], a[k + 1] = a[k];
        for (int i = 1; i <= k; i++) {
            if (a[i + 1] - a[i] > max_div) {
                max_ind = i;
                max_div = a[i + 1] - a[i];
            }
        }
        LL x = 0;
        vector<LL> tmp(k + 2);
        tmp = a;
        tmp.erase(tmp.begin() + max_ind);
        for (int i = 1; i <= k - 1; i += 2) {
            ans += tmp[i + 1] - tmp[i];
        }
        // cout << ans << endl;
        // for (auto t : tmp) cout << t << " ";
        tmp = a;
        tmp.erase(tmp.begin() + max_ind + 1);
        for (int i = 1; i <= k - 1; i += 2) {
            x += tmp[i + 1] - tmp[i];
        }
        ans = min(ans, x);
    }
    cout << ans;
    return 0;
}