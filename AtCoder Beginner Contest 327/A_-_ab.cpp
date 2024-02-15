#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    char tmp;
    for (int i = 0; i < n; i++) {
        if (i) {
            if ((s[i] == 'a' && tmp == 'b') || (s[i] == 'b' && tmp == 'a')) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        tmp = s[i];
    }
    cout << "No" << endl;
    return 0;
}