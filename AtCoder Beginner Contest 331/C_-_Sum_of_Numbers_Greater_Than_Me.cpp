#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1); // 原顺序
    vector<long long> pre(n + 1);
    map<int, int> ind;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        ind[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int p = ind[b[i]];
        cout << pre[n] - pre[p] << " ";
    }
    return 0;
}