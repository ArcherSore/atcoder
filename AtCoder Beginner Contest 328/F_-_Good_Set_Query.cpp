#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Node {
    int a, b;
    bool operator< (const Node & right) const {
        if (this->a < right.a)
            return true;
        else if (this->a == right.a) {
            if (this->b < right.b)
                return true;
        }
        return false;
    }
};

void deal(map<Node, long long> &base) {
    long long p, q;
    int cnt[4] = {0, 0, 0, 0};
    int flag = 1;
    for (auto x : base) {
        if (x.first.a == x.first.b - 1) {
            cnt[x.first.a]++, cnt[x.first.b - 1]++;
            if (flag) {
                p = x.second;
                flag = 0;
            } else {
                q = x.second;
            }
        }
    }
    int tmp = 0, t[2];
    for (int i = 1; i <= 3; i++) {
        if (cnt[i] == 2) {
            t[tmp++] = i;
        }
    }
    base[{t[0], t[1]}] = p + q;
    base[{t[1], t[0]}] = -p - q;
    return;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> ans;
    map<Node, long long> base;
    for (int i = 1; i <= Q; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if (!base.count({a, b})) {
            base[{a, b}] = d;
            base[{b, a}] = -d;
            ans.push_back(i);
        } else {
            if (base[{a, b}] == d) {
                ans.push_back(i);
            }
        }
        // 
        if (base.size() == 4) {
            deal(base);
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}