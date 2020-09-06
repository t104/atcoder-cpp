#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int h, w;

void dfs(P p, vector<string>& map, vector<vector<bool>>& pass) {
    if(pass.at(p.first).at(p.second)) return;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    rep(i, 4) {
        P next;
        next.first = p.first + dx.at(i);
        next.second = p.second + dy.at(i);
        if(0 <= next.first && next.first < w && 0 <= next.second && next.second < h &&
        map.at(next.first).at(next.second) != '#') {
            dfs(next, map, pass);
        }
    }
}

int main() {
    cin >> h >> w;
    vector<string> map(h);
    rep(i, h) cin >> map.at(i);
    P s, g;
    rep(i, h) {
        rep(j, w) {
            if(map.at(i).at(j) == 's') {
                s.first = i;
                s.second = j;
            } else if(map.at(i).at(j) == 'g') {
                g.first = i;
                g.second = j;
            }
        }
    }
    
    vector<vector<bool>> pass(h, vector<bool> (w, false));
    dfs(s, map, pass);
    if(pass.at(g.first).at(g.second)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}