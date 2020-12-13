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
const ll LINF = 1LL<<60;

const int dh[] = {0, 1, 0, -1};
const int dw[] = {1, 0, -1, 0};
int h, w, k;
vector<string> s;
vector<P> ans;

void trace(int x, int y, int d, vector<vector<int>> grid, vector<P> route) {
    grid.at(x).at(y) = 1;
    route.emplace_back(x, y);
    ++d;
    if (d == k) {
        ans = route;
        return;
    }
    rep(i,4) {
        int nx = x + dh[i];
        int ny = y + dw[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w && s.at(nx).at(ny) == '#' && grid.at(nx).at(ny) == 0) {
            trace(nx, ny, d, grid, route);
        }
    }
}

int main() {
    cin >> h >> w;
    s.resize(h);
    rep(i,h) cin >> s.at(i);
    k = 0;
    rep(i,h) rep(j,w) if (s.at(i).at(j) == '#') ++k;
    rep(i,h) rep(j,w) {
        if (s.at(i).at(j) == '#') trace(i, j, 0, vector<vector<int>>(h, vector<int>(w)), vector<P>(0));
    }
    cout << k << endl;
    rep(i,k) {
        cout << ans.at(i).first + 1 << ' ';
        cout << ans.at(i).second + 1 << endl;
    }
    return 0;
}