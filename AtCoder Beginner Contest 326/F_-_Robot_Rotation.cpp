#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X, Y, K;
int cnt = 0;
vector<int> a(N);
vector<int> p(N);

void dfs_x1(int lvl, int x) {
    if (lvl == K) {
        p[cnt++] = x;
        return;  
    }

    dfs_x1(lvl + 1, x + 1);
    dfs_x1(lvl + 1, x - 1);
    return;
}

void dfs_x2(int lvl, int x) {
    if (lvl == N) {

    }

    dfs_x2(lvl + 1, )
}

int main() {
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    K = N / 2;
    dfs_x1(0, 0);
    sort(p.begin(), p.begin() + cnt);
    dfs_x2(K, 0);

    return 0;
}