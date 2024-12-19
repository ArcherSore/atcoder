// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, LL>>> adj(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v;
        LL w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, -w);
    }
    
    vector<LL> ans(n + 1, 0);
    vector<bool> vis(n + 1, false);
    
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ans[i] = 0;
            vis[i] = true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(auto &[v, w] : adj[u]){
                    if(!vis[v]){
                        ans[v] = ans[u] + w;
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
