#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

// const int MAXN = 

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (i < 10) {
            if (a >= i) ans += 1;
            if (a >= i * 10 + i) ans += 1;
        } else {
            if (i % 10 == i / 10) {
                if (a >= (i % 10)) ans += 1;
                if (a >= i) ans += 1;
            }
        }
        
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}