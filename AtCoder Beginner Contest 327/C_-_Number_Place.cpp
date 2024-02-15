#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int map[10][10];
int row[10][10], col[10][10], grid[10][10];

int get_index(int i, int j) {
    if (1 <= j && j <= 3) {
        return 1 + (i - 1) / 3 * 3;
    } else if (4 <= j && j <= 6) {
        return 2 + (i - 1) / 3 * 3;
    } else {
        return 3 + (i - 1) / 3 * 3;
    }
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> map[i][j];
            row[i][map[i][j]]++;
            col[j][map[i][j]]++;
            grid[get_index(i, j)][map[i][j]]++;
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            // printf("i = %d, j = %d, row = %d, col = %d, grid = %d\n", i, j, row[i][j], col[i][j], grid[i][j]);
            if (row[i][j] != 1 || col[i][j] != 1 || grid[i][j] != 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}