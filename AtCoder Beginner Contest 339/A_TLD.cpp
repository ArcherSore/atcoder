#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <numeric>
using namespace std;

typedef long long LL;

int main() {
    string s;
    cin >> s;
    int pos;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '.') {
            pos = i + 1;
            break;
        }
    }
    for (int i = pos; i < s.size(); i++) {
        cout << s[i];
    }
    return 0;
}