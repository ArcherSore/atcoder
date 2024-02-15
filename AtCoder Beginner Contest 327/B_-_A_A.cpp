#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

long long ans[15] = {1, 4, 27, 256, 3125, 46656, 823543, 16777216, 387420489, 10000000000, 285311670611, 8916100448256, 302875106592253, 11112006825558016, 437893890380859375};

int main() {
    ios::sync_with_stdio(false);
    long long a;
    cin >> a;

    for (int i = 0; i < 15; i++) {
        if (ans[i] == a) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}