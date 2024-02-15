#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int s[1005][1005];
long long pre[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            s[i][j] = (c == 'B') ? 1 : 0;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + s[i][j];
        }
    }

    while (q--) {
        long long ans = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int n1 = (c + 1) / n - (a + 1) / n, n2 = (d + 1) / n - (b + 1) / n;
 
        int x1 = (a + 1) / n * n, y1 = (b + 1) / n * n;
        int x2 = (c + 1) / n * n, y2 = (d + 1) / n * n;
        printf("n1 = %d, n2 = %d, x1 = %d, y1 = %d, x2 = %d, y2 = %d\n", n1, n2, x1, y1, x2, y2);
        long long comp = n1 * n2;
        ans += comp * pre[n][n];
        
        comp = (c + 1) / n - (a + 1) / n;
        ans += comp * (pre[n][n] - pre[n][b % n + 1]);
        ans += comp * (pre[n][d % n + 1] - pre[n][0]);

        comp = (d + 1) / n - (b + 1) / n;
        ans += comp * (pre[n][n] - pre[a % n + 1][n]);
        ans += comp * (pre[c % n + 1][n] - pre[0][n]);

        ans += (pre[x1 % n + 1][y1 % n + 1] - pre[a % n + 1][b % n + 1]);
        ans += (pre[c % n + 1][d % n + 1] - pre[x2 % n + 1][y2 % n + 1]);
        ans += (pre[c % n + 1][y1 % n + 1] - pre[x2 % n + 1][b % n + 1]);
        ans += (pre[x1 % n + 1][d % n + 1] - pre[a % n + 1][y2 % n + 1]);

        cout << ans << endl;
    }
    return 0;
}