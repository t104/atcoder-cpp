#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 a,T2 l,T3 r){return l<=a && a<r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int dh[] = {0, 1, 0, -1};
const int dw[] = {1, 0, -1, 0};

int main() {
    int h, w;
    cin >> h >> w;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    vector<string> mp(h);
    rep(i,h) cin >> mp.at(i);
    vector<vector<int>> grid(h, vector<int>(w, INF));
    grid.at(sy).at(sx) = 0;
    queue<P> que;
    que.emplace(sy, sx);
    while(!que.empty()) {
        auto [y, x] = que.front(); que.pop();
        rep(i,4) {
            int ny = y + dh[i];
            int nx = x + dw[i];
            if (in(ny, 0, h) && in(nx, 0, w) && grid.at(ny).at(nx) == INF && mp.at(ny).at(nx) == '.') {
                grid.at(ny).at(nx) = grid.at(y).at(x) + 1;
                que.emplace(ny, nx);
            }
        }
    }
    cout << grid.at(gy).at(gx) << endl;
    return 0;
}