#include <bits/stdc++.h>
using namespace std;

long long abs(long long a, long long b) {
    return a > b ? a - b : b - a;
}

void solve() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long long x, y;
    if (x2 < x3 && y2 < y3) {
        cout << abs(x1 - x2) + abs(y1 - y2) + abs(x2 - x3) + abs(y2 - y3) + 1;
        return;
    } else if (x2 > x3 && y2 > y3) {
        cout << abs(x1 - x2) + abs(y1 - y2) + abs(x2 - x3) + abs(y2 - y3) + 1;
        return;
    } else if (x2 < x3 && y2 > y3) {
        cout << abs(x1 - x2) + abs(y1 - y2) + abs(x2 - x3) + abs(y2 - y3) + 1;
        return;
    } else if (x2 > x3 && y2 < y3) {
        cout << abs(x1 - x2) + abs(y1 - y2) + abs(x2 - x3) + abs(y2 - y3) + 1;
        return;
    }

    if (x2 == x3 && y2 < y3) {
        if (x1 == x2 && y1 > y2) {
            x = x2, y = y2 - 1;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) + 1;
        } else {
            x = x2, y = y2 - 1;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) - 1;
        }
        return;
    } else if (y2 == y3 && x2 < x3) {
        if (y1 == y2 && x1 > x2) {
            x = x2 - 1, y = y2;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) + 1;
        } else {
            x = x2 - 1, y = y2;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) - 1;
        }
        return;
    } else if (y2 == y3 && x2 > x3) {
        if (y1 == y2 && x1 < x2) {
            x = x2 + 1, y = y2;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) + 1;
        } else {
            x = x2 + 1, y = y2;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) - 1;
        }
        return;
    } else if ((x2 == x3 && y2 > y3)) {
        if (x1 == x2 && y1 < y2) {
            x = x2, y = y2 + 1;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) + 1;
        } else {
            x = x2, y = y2 + 1;
            cout << abs(x1 - x) + abs(y1 - y) + abs(x - x3) + abs(y - y3) - 1;
        }
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}