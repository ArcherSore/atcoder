#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
map<int, int> pre, post;

int get_pre(const string &s, const string &t) {
    // s是字串
    int pt = 0;
    for (int i = 0; i < t.size(); i++) {
        if (pt == t.size())
            break;
        if (s[pt] == t[i]) pt++;
    }
    return pt;
}

int get_post(const string &s, const string &t) {
    int pt = s.size() - 1;
    for (int i = t.size() - 1; i >= 0; i--) {
        if (pt < 0)
            break;
        if (s[pt] == t[i]) pt--;
    }
    return s.size() - pt - 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s, t;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> t;
        pre[get_pre(s, t)]++;
        post[get_post(s, t)]++;
    }
    // output();
    long long cnt = 0;
    for (auto x : pre) {
        for (auto y : post){
            if (x.first + y.first >= s.size()) {
                cnt += (long long)pre[x.first] * post[y.first];
            }
        }
    }
    cout << cnt << endl;
    return 0;
}