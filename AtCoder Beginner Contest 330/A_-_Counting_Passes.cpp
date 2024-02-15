#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0, sc;i < n; i++) {
        cin >> sc;
        if (sc >= k) ans ++;
    }
    cout << ans;
    return 0;
}