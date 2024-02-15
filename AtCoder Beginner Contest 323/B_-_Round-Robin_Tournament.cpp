#include <bits/stdc++.h>
using namespace std;

struct Player {
    int ind, wins;
} player[105];

bool cmp(const Player &a, const Player &b) {
    if (a.wins != b.wins) return a.wins > b.wins;
    return a.ind < b.ind;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int win = 0;
        for (auto x : s) {
            if (x == 'o') win += 1; 
        }
        player[i].wins = win;
        player[i].ind = i + 1;
    }
    sort(player, player + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << player[i].ind << " ";
    }
    return 0;
}