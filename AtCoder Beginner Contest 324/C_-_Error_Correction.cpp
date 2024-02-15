#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
vector<int> ans;

int dif(string &s, string &t) {
    int n = s.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i])
            cnt++;
    }
    return cnt;
}

bool common(string &s, string &t) {
    // s > t
    int ns = s.size(), nt = t.size();
    int pre = 0;
    for (int i = 0; i < ns; i++) {
        if (s[pre] != t[i])
            break;
        pre++;
    }
    int post = ns - 1;
    for (int i = nt - 1; post >= 0; i--) {
        if (s[post] != t[i])
            break;
        post--;
    }
    return pre >= post;
}

int main() {
    int k, cnt = 0;
    string s, t;
    cin >> k >> s;
    for (int i = 1; i <= k; i++) {
        cin >> t;
        int ns = s.size(), nt = t.size();
        if (abs(ns - nt) > 1)
            continue;

        if (ns == nt) {
            // 替换
            if (dif(s, t) <= 1) {
                ans.push_back(i);
            }
        }
        else if (ns > nt) {
            // 删除
            if (common(s, t)) {
                ans.push_back(i);
            }
        }
        else {
            // 插入
            if (common(t, s)) {
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " " ;
    }
    return 0;
}