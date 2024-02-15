#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++) {
        ind[i] = i;
    }
    vector<map<int, int> > arr(n + 1);
    for (int i = 1, color; i <= n; i++) {
        scanf("%d", &color);
        arr[i][color] = 1;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        if (arr[ind[l]].size() > arr[ind[r]].size()) {
            swap(ind[l], ind[r]);
        }
        for (auto x : arr[ind[l]]) {
            arr[ind[r]][x.first]++;
        }
        arr[ind[l]].clear();

        // printf("Index: ");
        // for (int i = 1; i <= n; i++) {
        //     printf("%d ", ind[i]);
        // }
        // printf("\n");

        printf("%ld\n", arr[ind[r]].size());
    }
    return 0;
}