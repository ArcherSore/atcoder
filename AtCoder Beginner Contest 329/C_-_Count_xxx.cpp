#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int last = 0, ans = 0;
    map<char, int> length;
    length[s[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            int len = i - last;
            string tmp = s.substr(last, len);
            if (len > length[s[i - 1]]) {
                length[s[i - 1]] = len;
            }
            last = i;
        }
    }
    if (n - last > length[s[n - 1]]) {
        length[s[n - 1]] = n - last;
    }
    for (auto x : length) {
        ans += x.second;
    }
    cout << ans << endl;
    return 0;
}