#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    vector<vector<int>> grid(h, vector<int>(w, INF));
    int sh, sw, gh, gw;
    vector<vector<P>> tel(26);
    vector<bool> teleported(26, false);
    rep(i,h) rep(j,w) {
        if (a[i][j] == 'S') {
            sh = i;
            sw = j;
        }
        if (a[i][j] == 'G') {
            gh = i;
            gw = j;
        }
        if ('a' <= a[i][j] && a[i][j] <= 'z') {
            tel[a[i][j] - 'a'].push_back({i, j});
        }
    }

    queue<P> que;
    grid[sh][sw] = 0;
    que.push({sh, sw});
    vector<P> step = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    while(!que.empty()) {
        int nh = que.front().first;
        int nw = que.front().second;
        que.pop();

        if ('a' <= a[nh][nw] && a[nh][nw] <= 'z' && !teleported[a[nh][nw] - 'a']) {
            teleported[a[nh][nw] - 'a'] = true;
            for (auto p : tel.at(a[nh][nw] - 'a')) {
                if (p.first == nh && p.second == nw) continue;
                if (grid[nh][nw] + 1 < grid[p.first][p.second]) {
                    grid[p.first][p.second] = grid[nh][nw] + 1;
                    que.push(p);
                }
            }
        }

        for (auto st : step) {
            int mh = nh + st.first;
            int mw = nw + st.second;
            if (0 <= mh && mh < h && 0 <= mw && mw < w && a[mh][mw] != '#') {
                if (grid[nh][nw] + 1 < grid[mh][mw]) {
                    grid[mh][mw] = grid[nh][nw] + 1;
                    que.push({mh, mw});
                }
            }
        }

    }

    if (grid[gh][gw] == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << grid[gh][gw] << endl;
    return 0;
}