#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
struct Point {
    long long l, r;
} p[MAXN];

bool cmp(Point &a, Point &b) {
    if (a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}

int main() {
    int n;
    cin >> n;
    ll l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        p[i].l = l, p[i].r = l + r;
    }
    sort(p, p + n, cmp);
    
    ll now = 1; // 枚举时间
    int ans = 0, ptr = 0; // ptr 记录枚举到第几个区间
    priority_queue<ll, vector<ll>, greater<ll> > pq; // 存区间离开的时间
    while (ptr < n || !pq.empty()) {
        // 弹出已经离开区间的
        while (!pq.empty() && pq.top() < now) {
            pq.pop();
        }
        // 压入应该加入的区间
        while (ptr < n && p[ptr].l <= now) {
            pq.push(p[ptr++].r);
        }
        if (!pq.empty()) {
            ans++;
            pq.pop();
            now++;
        } else {
            // TODO
            now = p[ptr].l;
        }
    } 
    cout << ans << endl;
    return 0;
}