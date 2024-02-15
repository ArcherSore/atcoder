#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;

int main() {
    string s;
    cin >> s;
    queue<char> q;
    q.push('A'), q.push('B'), q.push('C');
    for (int i= 0; i < s.size(); i++) {
        while (!q.empty() && q.front() != s[i]) {
            q.pop();
        }
        if (q.empty()) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}