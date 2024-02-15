#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
struct Edge {
    int id, w;
};
vector<vector<Edge>> eg(MAXN);

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, b, c; i < m; i++) {
        cin >> u >> v >> b >> c;
        e[u].push_back({v, b, c});
    }
    return 0;
}