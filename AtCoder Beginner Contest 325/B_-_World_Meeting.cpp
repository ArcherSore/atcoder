#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int w[MAXN], x[MAXN];

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> w[i] >> x[i];
    }

    int ans = 0, cnt;
    for (int i = 0; i < 24; i++) {
        cnt = 0;
        for (int j = 0; j < T; j++) {
            // i 开始时间, j 基地
            if (((x[j] + i) % 24) >= 9 && ((x[j] + i) % 24) <= 17) {
                cnt += w[j];
            }
        }
        // cout << "i = " << i << ", cnt = " << cnt << endl;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}