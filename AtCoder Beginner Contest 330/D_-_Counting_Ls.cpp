#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

char s[2005][2005];
int row[2005], col[2005];
vector<int> G[2005];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'o') {
                row[i] += 1;
                col[j] += 1;
                G[i].push_back(j);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'o') {
                ans += (row[i] - 1) * (col[j] - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}