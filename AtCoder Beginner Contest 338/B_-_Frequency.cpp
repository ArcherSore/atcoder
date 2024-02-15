#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int num[256] = {0};
    for (int i = 0; s[i]; i++) {
        num[s[i]]++;
    }
    int mx = 0, pos;
    for (int i = 0; i < 256; i++) {
        if (num[i] > mx) {
            mx = num[i];
            pos = i;
        }
    }
    cout << (char)pos;
    return 0;
}