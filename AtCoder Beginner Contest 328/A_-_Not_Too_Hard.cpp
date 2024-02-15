#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

// const int MAXN = 

int main() {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x <= k) ans += x;
    }
    cout << ans << endl;
    return 0;
}