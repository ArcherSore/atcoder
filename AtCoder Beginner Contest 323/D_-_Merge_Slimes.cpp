#include <bits/stdc++.h>
using namespace std;

long long tle[70];

void pre() {
    long long x = 1;
    for (int i = 0; i < 63; i++) {
        tle[i] = x;
        x *= 2;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    int n;
    cin >> n;
    map<long long, long long> arr;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    for (int i = 0; i < n; i++) {
        long long s, c;
        cin >> s >> c;
        arr[s] = c;
        q.push(s);
    }

    while (!q.empty()) {
        long long s = q.top();
        q.pop();
        long long c = arr[s];
        if (c <= 1) continue; 
        for (int i = 62; i >= 0 && c; i--) {
            if (c >= tle[i]) {
                if (!arr.count(tle[i] * s)) {
                    q.push(tle[i] * s);
                }
                arr[tle[i] * s] += 1;
                arr[s] -= tle[i];
                c -= tle[i];
            }
            // if (!arr.count(2 * s)) {
            //     q.push(2 * s);
            // }
            // arr[s * 2] += c / 2;
            // arr[s] = c % 2;
        }
        
    }
    
    long long ans = 0;
    for (auto x : arr) {
        ans += x.second;
    }
    cout << ans << endl;
    return 0;
}