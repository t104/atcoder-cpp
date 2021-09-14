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

int main() {
    const int nrow = 9, ncol = 9;
    int w, h;
    int dh = 0, dw = 0;
    string dir;
    cin >> w >> h >> dir;
    --w, --h;
    for (char c: dir) {
        if (c == 'R') dw = 1;
        if (c == 'L') dw = -1;
        if (c == 'U') dh = -1;
        if (c == 'D') dh = 1;
    }
    vector<string> tbl(nrow);
    rep(i,nrow) cin >> tbl[i];
    string ans;
    while (ans.size() < 4) {
        ans.push_back(tbl[h][w]);
        int nh = h + dh, nw = w + dw;
        if (nh < 0 || nrow <= nh) dh *= -1;
        if (nw < 0 || ncol <= nw) dw *= -1;
        h += dh;
        w += dw;
    }
    cout << ans << endl;
    return 0;
}

