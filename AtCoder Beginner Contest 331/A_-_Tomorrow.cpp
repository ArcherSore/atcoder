#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int M, D;
    cin >> M >> D;
    int y, m, d;
    cin >> y >> m >> d;
    d += 1;
    if (d > D) {
        m += 1;
        d = 1;
    }
    if (m > M) {
        y += 1;
        m -= M;
    }
    cout << y << " " << m << " " << d;
    return 0;
}