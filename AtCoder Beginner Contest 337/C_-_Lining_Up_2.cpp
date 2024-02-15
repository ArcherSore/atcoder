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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> behind;

    queue<int> seq;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            seq.push(i);
            continue;
        }
        behind[a[i]] = i;
    }
    while ((int)seq.size() != n) {
        seq.push(behind[seq.back()]);
    }

    while (!seq.empty()) {
        cout << seq.front() << " ";

        seq.pop();
    }
    return 0;
}