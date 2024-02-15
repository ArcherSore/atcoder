#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    string T;
    cin >> n >> T;
    sort(T.begin(), T.end());
    if (T.back() == '0') {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for (long long i = 1; ; i++) {
        long long val = i * i;
        string S = to_string(val);
        if (S.size() > T.size())
            break;
        while (T.size() > S.size()) {
            S.push_back('0');
        }
        sort(S.begin(), S.end());
        if (S == T)
            ans++;
    }
    cout << ans << endl;
    return 0;
}