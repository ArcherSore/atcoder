#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


const int MAXN = 300005;
char s[MAXN];
int same[MAXN];

int main() {
    int n, Q;
    cin >> n >> Q;
    scanf("%s", s + 1);
    for (int i = 1; i <= strlen(s + 1); i++) {
        if (s[i] == s[i - 1]) same[i] = same[i - 1] + 1;
        else same[i] = same[i - 1];
        // cout << same[i] << endl;
    }
    
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << same[r] - same[l] << endl;
    }
    return 0;
}