#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

vector<string> c;
vector<vector<int>> grid;
int h, w, ans;


const vector<P> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void dfs(int hi, int wi, int sh, int sw) {
    for (auto [dh,dw]: d) {
        int nh = hi + dh;
        int nw = wi + dw;
        if (nh == sh && nw == sw) {
            chmax(ans, grid[hi][wi] + 1);
        }
        if (in(nh, 0, h) && in(nw, 0, w) && c[nh][nw] == '.' && grid[nh][nw] == -1) {
            grid[nh][nw] = grid[hi][wi] + 1;
            dfs(nh, nw, sh, sw);
        }
    }
    grid[hi][wi] = -1;
}

int main() {
    cin >> h >> w;
    c.resize(h);
    grid.resize(h, vector<int>(w, -1));
    rep(i,h) cin >> c[i];
    ans = 0;
    rep(i,h) rep(j,w) {
        if (c[i][j] == '#') continue;
        grid[i][j] = 0;
        dfs(i, j, i, j);
        grid[i][j] = -1;
    }

    if (ans < 3) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}