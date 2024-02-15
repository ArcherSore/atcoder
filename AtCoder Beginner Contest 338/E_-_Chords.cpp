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
    int n, a, b;
    cin >> n;

    deque<int> q;
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        pos[a] = b;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (pos.find(i) != pos.end()) q.push_back(i);
        else {
            if (pos[q.back()] == i) {
                q.pop_back();
            }
            else {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}