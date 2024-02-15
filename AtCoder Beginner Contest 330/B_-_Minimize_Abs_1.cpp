#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x <= l) cout << l << " ";
        else if (x >= r) cout << r << " ";
        else cout << x << " ";
    }
    return 0;
}