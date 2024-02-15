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
    if (isupper(s[0])) {
        int flag = 1;
        for (int i = 1; s[i]; i++){
            if (islower(s[i])) continue;
            else {
                cout << "No";
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes";
        }
    } else {
        cout << "No";
    }

    return 0;
}