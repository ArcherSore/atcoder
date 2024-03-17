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
using LL = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> nums(30);
    vector<int> dif(n + 1);
    nums[s[0] - 'a']++, dif[0] = 0;
    for (int i = 1; i < n; i++) {
        nums[s[i] - 'a']++;
        dif[i] = (i + 1) - nums[s[i] - 'a'];
    }

    LL res = 0;
    for (int i = 0; i < n; i++) {
        // cout << dif[i] << " ";
        res += dif[i];
    }

    for (int i = 0; i < 26; i++) {
        if (nums[i] > 1) {
            res += 1;
            break;
        }
    }
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}