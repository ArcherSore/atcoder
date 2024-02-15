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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    map<int, int> num;

    set<int> exist;
    map<int, int> sec_num;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
        if ((int)exist.size() < m) {
            if (exist.find(a[i]) == exist.end())
                exist.insert(a[i]);
            sec_num[a[i]]++;
        }
    }

    for (int r = 0; r < n; r++) {
        int ans = 0;
        for (auto x : exist) {
            ans += min(num[x], k);
        }
        printf("%d\n", ans);
        sec_num[a[r + 1]]--;
        if (sec_num[a[r + 1]] == 0) {
            exist.erase(a[r + 1]);
        }

        int p = r + m + 1;
        if (p > n) p -= n;
        while ((int)exist.size() < m) {
            if (exist.find(a[p]) == exist.end()) {
                exist.insert(a[p]);
            }
            sec_num[a[p]]++;
            p++;
            if (p > n) p -= n;
        } 
    }
    
    return 0;
}