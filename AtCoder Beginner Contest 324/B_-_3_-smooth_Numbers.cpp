#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n != 1) {
        int ok = 0;
        if (n % 2 == 0) {
            ok = 1;
            n /= 2;
        }
        if (n % 3 == 0) {
            ok = 1;
            n /= 3;
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
} 