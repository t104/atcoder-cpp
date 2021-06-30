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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w)), d(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    rep(i,h) rep(j,w) d[i][j] = b[i][j] - a[i][j];
    ll cnt = 0;
    rep(i,h-1) {
        rep(j,w-1) {
            d[i+1][j] -= d[i][j];
            d[i][j+1] -= d[i][j];
            d[i+1][j+1] -= d[i][j];
            cnt += abs(d[i][j]);
            d[i][j] = 0;
        }
    }
    bool ok = true;
    rep(i,h) rep(j,w) {
        if (d[i][j] != 0) ok = false;
    }
    if (ok) {
        cout << "Yes" << endl;
        cout << cnt << endl;
    }
    else cout << "No" << endl;
    return 0;
}