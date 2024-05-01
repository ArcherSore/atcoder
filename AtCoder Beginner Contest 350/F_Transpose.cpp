#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int N = 5e5 + 10;

string s;
vector<int> match(N);

void flip(int i) {
    if (isupper(s[i])) {
        s[i] -= 'A' - 'a';
    } else {
        s[i] += 'A' - 'a';
    }
}

void dfs(int x, int y, int flag) {
    if (x > y) {
        return;
    }
    // 0 没拆括号 1 拆了括号
    if (flag) {
        for (int i = y; i >= x; i--) {
            if (s[i] == ')') {
                dfs(match[i] + 1, i - 1, 0);
                i = match[i];
            } else {
                cout << s[i];
            }
        }
    } else {
        for (int i = x; i <= y; i++) {
            if (s[i] == '(') {
                dfs(i + 1, match[i] - 1, 1);
                i = match[i];
            } else {
                cout << s[i];
            }
        }
    }
}

void solve() {
    cin >> s;
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            match[i] = st.top();
            match[st.top()] = i;
            st.pop();
        } else {
            if (st.size() % 2) {
                flip(i);
            }
        }
    }
    dfs(0, n - 1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}