#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// https://atcoder.jp/contests/abc176/submissions/16103551


const int wall = 1e9 + 1;

int main() {
    int h, w;
    cin >> h >> w;
    P c, d;
    cin >> c.first >> c.second;
    c.first--; c.second--;
    cin >> d.first >> d.second;
    d.first--; d.second--;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    
    const int wall = 1e9 + 1;
    vector<vector<int>> grid(h, vector<int>(w, 1e9));
    rep(i,h) rep(j,w) {
        if (s.at(i).at(j) == '#') grid.at(i).at(j) = wall;
    }

    queue<P> que;
    vector<P> step = {
        make_pair(1,0),
        make_pair(0,1),
        make_pair(-1,0),
        make_pair(0,-1)
        };
    vector<P> magic;
    for (int i = -2; i <= 2; ++i) for (int j = -2; j <= 2; ++j) {
        if (i ==0 && j == 0) continue;
        magic.push_back(make_pair(i,j));
    }
    auto available = [&](P p) {
        return (0 <= p.first && p.first < h && 0 <= p.second && p.second < w
        && grid.at(p.first).at(p.second) < wall);
    };
    auto checkWall = [&](P p) {
        return (0 <= p.first && p.first < h && 0 <= p.second && p.second < w
        && grid.at(p.first).at(p.second) == wall);
    };
    que.push(c);
    grid.at(c.first).at(c.second) = 0;
    while(!que.empty()) {
        P p = que.front(); que.pop();
        P next;
        bool iswall = false;
        for (auto st : step) {
            next.first = p.first + st.first;
            next.second = p.second + st.second;
            if (available(next) && grid.at(next.first).at(next.second) > grid.at(p.first).at(p.second)) {
                grid.at(next.first).at(next.second) = grid.at(p.first).at(p.second);
                que.push(next);
            }
            if (checkWall(next)) iswall = true;
        }
        if (iswall) {
            for (auto m : magic) {
                next.first = p.first + m.first;
                next.second = p.second + m.second;
                if (available(next) && grid.at(p.first).at(p.second) + 1 < grid.at(next.first).at(next.second)) {
                    grid.at(next.first).at(next.second) = grid.at(p.first).at(p.second) + 1;
                    que.push(next);
                }
            }
        }
    }
    if (grid.at(d.first).at(d.second) == 1e9) cout << -1 << endl;
    else cout << grid.at(d.first).at(d.second) << endl;
    return 0;
}