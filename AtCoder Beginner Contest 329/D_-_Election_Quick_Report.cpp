#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Candidate {
    int ind, votes;
    bool operator<(const Candidate &a)const {
        if (this->votes != a.votes)
            return this->votes < a.votes;
        return this->ind > a.ind;
    }
};

priority_queue<Candidate> q;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        q.push({i, 0});
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    // init(n);
    vector<int> arr(n + 1);
    for (int i = 0, vote; i < m; i++) {
        cin >> vote;
        arr[vote]++;
        q.push({vote, arr[vote]});
        printf("%d\n", q.top().ind);
    }
    return 0;
}