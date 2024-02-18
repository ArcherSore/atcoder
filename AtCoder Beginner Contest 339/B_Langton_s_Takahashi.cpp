#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <numeric>
using namespace std;

typedef long long LL;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Person {
    int x, y;
    int dir;
};

void print(vector<vector<char>> &cell, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cell[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> cell(n, vector<char> (m, '.'));
    Person p = {0, 0, 0};
    while (k--) {
        if (cell[p.x][p.y] == '.') {
            cell[p.x][p.y] = '#';
            p.dir = (p.dir + 1) % 4;
            p.x = (p.x + dx[p.dir] + n) % n;
            p.y = (p.y + dy[p.dir] + m) % m;
        } else {
            cell[p.x][p.y] = '.';
            p.dir = (p.dir + 3) % 4;
            p.x = (p.x + dx[p.dir] + n) % n;
            p.y = (p.y + dy[p.dir] + m) % m;
        }
        // print(cell, n, m);
    }

    print(cell, n, m);
    return 0;
}