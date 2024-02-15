#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int main() {
    int x, y;
    cin >> x >> y;
    if (x < y) {
        if (abs(x - y) <= 2) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    } else {
        if (abs(x - y) <= 3) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    return 0;
}