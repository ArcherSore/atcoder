#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;

bool match(const string &s, string &t) {
    int len = s.size();
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '#') continue;
        if (s[i] == t[i]) flag = 1;
        else {
            flag = 0;
            break;
        }
    }
    return flag;
}

void rep(int p, string &s, string &t) {
    for (int i = max(0, p - m + 1); i <= min(n - m, p + m - 1); i++) {
        if (match(s.substr(i, m), t)) {
            s = s.replace(i, m, m, '#');
            rep(i, s, t);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i <= n - m; i++) {
        if (s.substr(i, m) == t) {
            s = s.replace(i, m, m, '#');
            rep(i, s, t);
        }
    }
    if (s == string(n, '#')) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}