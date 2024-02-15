#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int last;
    cin >> last;
    for (int i = 1, a; i < n; i++) {
        cin >> a;
        if (last != a) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}