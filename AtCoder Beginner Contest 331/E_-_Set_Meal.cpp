#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

const int MAXN = 1e5;

struct Dish {
    int ind, cost;
} cost[2 * MAXN];

struct Main {
    int ind, cost;
} ma[MAXN];

struct Side {
    int ind, cost;
} si[MAXN];

map<pair<int, int>, int> vis;

bool cmp(const Dish &a, const Dish &b) {
    return a.cost > b.cost;
}
bool cmp1(const Main &a, const Main &b) {
    return a.cost > b.cost;
}
bool cmp2(const Side &a, const Side &b) {
    return a.cost > b.cost;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        cin >> ma[i].cost;
        ma[i].ind = i;
        cost[i].cost = ma[i].cost;
        cost[i].ind = i;
    }
    for (int i = n; i < n + m; i++) {
        cin >> si[i - n].cost;
        si[i - n].ind = i - n;
        cost[i].cost = si[i - n].cost;
        cost[i].ind = i;
    }
    sort(cost, cost + n + m, cmp);
    sort(ma, ma + n, cmp1);
    sort(si, si + m, cmp2);

    for (int i = 0, c, d; i < l; i++) {
        cin >> c >> d;
        vis[{c - 1, d - 1}] = 1; 
    }

    long long ans = 0;
    for (int i = 0; i < n + m; i++) {
        if (cost[i].ind < n) {
            // is main dish
            for (int j = 0; j < m; j++) {
                if (!vis[{cost[i].ind, si[j].ind}]) {
                    ans = max(ans, 1LL * cost[i].cost + si[j].cost);
                    break;
                }
            }
        } else {
            // is side dish
            for (int j = 0; j < n; j++) {
                if (!vis[{ma[j].ind, cost[i].ind - n}]) {
                    ans = max(ans, 1LL * ma[j].cost + cost[i].cost);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}