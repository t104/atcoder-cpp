#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int h,w,n;
int table[105][105];

P next (P now) {
    if (now.first%2 == 0) {
        if (now.second+1 < w) return make_pair(now.first, now.second+1);
        return make_pair(now.first+1, now.second);
    }
    if (0 < now.second) return make_pair(now.first, now.second-1);
    return make_pair(now.first+1, now.second);
}

int main() {
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    P now = make_pair(0,0);
    rep(i,n) {
        rep(j,a.at(i)) {
            table[now.first][now.second] = i+1;
            now = next(now);
        }
    }
    rep(i,h) {
        rep(j,w) {
            cout << table[i][j];
            if (j != w-1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}