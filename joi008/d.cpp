#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

const int dh[] = {0, 1, 0, -1};
const int dw[] = {1, 0, -1, 0};

int h, w;
int ans = 0;
void dfs(int x, int y, int len, vector<vector<int>> grid){
    grid.at(x).at(y) = 1;
    chmax(ans, len);
    rep(i,4) {
        int nx = x + dh[i];
        int ny = y + dw[i];
        if (in(nx, 0, h) && in(ny, 0, w) && grid.at(nx).at(ny) == 0) {
            dfs(nx, ny, len + 1, grid);
        }
    }
}

int main() {
    cin >> w >> h;
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i,h) rep(j,w) {
        cin >> grid.at(i).at(j);
        grid.at(i).at(j)--;
    }
    
    rep(i,h) rep(j,w) {
        dfs(i, j, 0, grid);
    }
    cout << ans << endl;
    
    return 0;
}