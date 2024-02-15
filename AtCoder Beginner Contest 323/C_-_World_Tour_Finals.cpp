#include <bits/stdc++.h>
using namespace std;

struct Score {
    int score, ind;
} scores[105];

bool cmp(const Score &a, const Score &b) {
    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> player_scores(n);
    for (int i = 0; i < m; i++) {
        cin >> scores[i].score;
        scores[i].ind = i;
    }

    vector<string> wins(n);
    int max_score = 0;
    for (int i = 0; i < n; i++) {
        cin >> wins[i];
        player_scores[i] = i + 1;
        for (int j = 0; j < m; j++) {
            if (wins[i][j] == 'o') {
                player_scores[i] += scores[j].score;
            }
        }
        max_score = max(max_score, player_scores[i]);
    }
   // cout << max_score << endl;

    sort(scores, scores + m, cmp);

    for (int i = 0; i < n; i++) {
        int cnt = 0, pos = 0;
        while (player_scores[i] < max_score) {
            // cout << "?? " << endl;
            while (wins[i][scores[pos].ind] == 'o') {
                pos++;
            }
            player_scores[i] += scores[pos].score;
            cnt++, pos++;
        }
        cout << cnt << endl;
    }

    return 0;
}