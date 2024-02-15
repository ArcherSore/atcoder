#include <iostream>
using namespace std;

typedef long long LL;

int main() {
    LL a, m, l, r;
    cin >> a >> m >> l >> r;
    LL p1 = a + (l - a) / m * m, p2 = a + (r - a) / m * m;
    if (p1 < l && r < p2) { 
        cout << 0;
        return 0;
    }
    if (p1 < l) p1 += m;
    if (p2 > r) p2 -= m;
    
    cout << (p2 - p1) / m + 1;
    return 0;
}