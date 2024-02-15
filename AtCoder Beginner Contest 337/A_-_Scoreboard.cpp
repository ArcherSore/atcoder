#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    LL sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum1 += a[i];
        sum2 += b[i];
    }
    if (sum1 > sum2) cout << "Takahashi";
    else if (sum1 < sum2) cout << "Aoki";
    else cout << "Draw";
    return 0;
}