#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n); //
    vector<int> mi(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        mi[i] = a[i] - a[i - 1];
    }

    queue<int> q;
    int sum = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        q.push(mi[i]);
        sum += mi[i];
        while (sum > m - 1) {
            sum -= q.front();
            q.pop();
        }
        ans = max(ans, int(q.size()));
    }
    cout << ans + 1 << endl;
    return 0;
}