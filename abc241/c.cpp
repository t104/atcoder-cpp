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

vector<vector<int>> grid;
int n;

void calc(int h, int w, int dh, int dw) {
    int cnt = 0;
    rep(i,6) {
        if (in(h, 0, n) && in(w, 0, n)) {
            cnt += grid[h][w];
        } else {
            return;
        }
        h += dh;
        w += dw;
    }
    if (4 <= cnt) {
        cout << "Yes" << endl;
        exit(0);
    }
}

int main() {
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    grid.resize(n, vector<int>(n));
    rep(i,n) rep(j,n) grid[i][j] = s[i][j] == '#';
    vector<P> d = {
        {0, 1},
        {1, 0},
        {1, 1},
        {-1, 1}
    };
    rep(i,n) rep(j,n) {
        for (auto [dh, dw] : d) {
            calc(i, j, dh, dw);
        }
    }
    cout << "No" << endl;
    return 0;
}