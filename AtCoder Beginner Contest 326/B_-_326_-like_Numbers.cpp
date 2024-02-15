#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

bool is(int x) {
    return (x % 10) == (x / 100) * (x / 10 % 10);
}

int main() {
    int n;
    cin >> n;
    for (int i = n; ; i++) {
        if (is(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}