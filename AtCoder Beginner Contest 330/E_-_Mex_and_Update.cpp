#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef long long LL;
const int MAXN = 2e5 + 5;

int main() {    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= n)
            cnt[a[i]]++;
    }

    set<int> nums; // 维护0~n中没出现过的数字
    for (int i = 0; i <= n; i++) {
        if (!cnt[i]) {
            nums.insert(i);
        }
    }

    while (q--) {
        int x, c;
        cin >> x >> c;
        if (a[x] <= n) {
            cnt[a[x]]--;
            if (cnt[a[x]] == 0) {
                nums.insert(a[x]);
            }
        }
        a[x] = c;
        if (a[x] <= n) {
            cnt[a[x]]++;
            if (cnt[a[x]] == 1) {
                nums.erase(a[x]);
            }
        }
        cout << *nums.begin() << '\n';
    }
    return 0;
}