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

const int MAXN = 3e5 + 10;

int nxt[MAXN][26], cnt;
int val[MAXN];

void insert(string &s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (!nxt[p][ind]) {
            nxt[p][ind] = ++cnt;
        }
        p = nxt[p][ind];
        val[p] += 1;
    }
}

LL find(string &s) {
    int p = 0;
    LL res = 0;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        res += 1LL * val[p];
        if (!nxt[p][ind]) {
            return res;
        }
        p = nxt[p][ind];
    }
    return res + 1LL * val[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    LL res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += find(s[i]);
        insert(s[i]);
    }
    cout << res << '\n';

    return 0;
}