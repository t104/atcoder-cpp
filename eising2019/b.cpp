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

int h, w;
vector<string> grid;
vector<vector<bool>> visited;
const vector<P> d = {
    {1,0}, {0,1}, {-1,0}, {0,-1}
};


void dfs(int hi, int wi, ll &black, ll &white) {
    if (visited[hi][wi]) return;
    if (grid[hi][wi] == '#') black++;
    else white++;
    visited[hi][wi] = true;

    for (auto [dh, dw]: d) {
        int nh = hi + dh;
        int nw = wi + dw;
        if (in(nh, 0, h)
        && in(nw, 0 ,w)
        && grid[hi][wi] != grid[nh][nw]) {
            dfs(nh, nw, black, white);
        }
    }
}


int main() {
    cin >> h >> w;
    grid.resize(h);
    visited.resize(h,vector<bool>(w, false));
    
    ll ans = 0;
    rep(i,h) cin >> grid[i];
    rep(i,h) rep(j,w) {
        ll black = 0, white = 0;
        dfs(i,j, black, white);
        ans += black*white;
    }
    cout << ans << endl;
    return 0;
}