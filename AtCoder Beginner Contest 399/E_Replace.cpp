#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, s;
    DSU(int n) : parent(n), s(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        while (x != parent[x])
            x = parent[x] = parent[parent[x]];
        return x;
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
            s[a] += s[b];
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    string S, T;
    cin >> S >> T;
    
    vector<int> f(26, -1);
    for (int i = 0; i < N; i++){
        int s = S[i] - 'a', t = T[i] - 'a';
        if (f[s] == -1) {
            f[s] = t;
        } else if (f[s] != t) {
            cout << -1 << "\n";
            return 0;
        }
    }
    
    int ans = 0; 
    vector<bool> usedT(26, false);
    DSU dsu(26);
    
    for (int i = 0; i < 26; i++){
        if (f[i] != -1) {
            usedT[f[i]] = true;
        }
        if (f[i] != -1 && f[i] != i) {
            ans++;
            dsu.merge(i, f[i]);
        }
    }
    
    vector<int> cnt(26, 0);
    for (int i = 0; i < 26; i++){
        if (usedT[i]) {
            cnt[dsu.find(i)]++;
        }
    }
    
    for (int i = 0; i < 26; i++){
        if (dsu.find(i) == i && cnt[i] > 1 && cnt[i] == dsu.s[i]) {
            if (count(usedT.begin(), usedT.end(), true) == 26) {
                cout << -1 << "\n";
                return 0;
            }
            ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}