#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    vector<char> a;
    int k = 0;
    for (auto c : s) {
        if (c == '<' || c == '>') {
            a.push_back(c);
        } else {
            k++;
        }
    }
    if (a.size() != 2 || k < 1) {
        cout << "No\n";
    } else {
        if (a[0] == '<' && a[1] == '>') {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}