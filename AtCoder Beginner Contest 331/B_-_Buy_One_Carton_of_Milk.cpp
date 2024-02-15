#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, s, m, l;
int ans = 1000001;

void dfs(int x, int v) {
    if (x >= n) {
        ans = min(ans, v);
        return;
    }
    dfs(x + 6, v + s);
    dfs(x + 8, v + m);
    dfs(x + 12, v + l);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> s >> m >> l;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}