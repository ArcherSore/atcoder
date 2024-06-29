// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<int> LIS(vector<int> &v) {
    int n = v.size();
    vector<int> seq, f;
    seq.push_back(v[0]);
    f.push_back(1);

    for (int i = 1; i < n; i++) {
        int p;
        if (v[i] > seq.back()) {
            p = seq.size();
            seq.push_back(v[i]);
        } else {
            p = lower_bound(seq.begin(), seq.end(), v[i]) - seq.begin();
            seq[p] = v[i];
        }
        f.push_back(p + 1);
    }
    return f;
}

vector<int> LDS(vector<int> &v) {
    int n = v.size();
    vector<int> seq, f;
    seq.push_back(v[0]);
    f.push_back(1);

    for (int i = 1; i < n; i++) {
        int p;
        if (v[i] < seq.back()) {
            p = seq.size();
            seq.push_back(v[i]);
        } else {
            p = lower_bound(seq.begin(), seq.end(), v[i], greater ()) - seq.begin();
            seq[p] = v[i];
        }
        f.push_back(p + 1);
    }
    return f;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];    
    }
    
    vector<int> f1, f2;
    f1 = LIS(v);
    reverse(v.begin(), v.end());
    f2 = LDS(v);
    reverse(f2.begin(), f2.end());

    int max_len = 0;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, f1[i] + f2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (f1[i] + f2[i] ==  max_len) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}