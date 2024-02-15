#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;

vector<LL> nums;

int main() {
    LL n;
    cin >> n;
    for (int i = 0; 1LL * i * i <= n; i++) {
        nums.push_back(1LL * i * i);
    }
    LL ans = 1e12;
    for (auto x : nums) {
        auto it = lower_bound(nums.begin(), nums.end(), n - x);
        if (it != nums.end()) {
            ans = min(ans, *it + x - n);
        }
        if (it != nums.begin()) {
            ans = min(ans, n - x - *(it - 1));
        }
    }
    cout << ans << '\n';
    return 0;
}