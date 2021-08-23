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

vector<P> d = {{1,0}, {0,1}};

int main() {
    int h, w;
    ll c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    ll ans = LINF;
    rep(_, 2) {
        vector dp(h, vector<ll>(w, LINF));
        rep(i,h) rep(j,w) {
            chmin(dp[i][j], a[i][j]);
            if (0 <= i-1) {
                chmin(ans, dp[i-1][j] + c + a[i][j]);
                chmin(dp[i][j], dp[i-1][j] + c);
            }
            if (0 <= j-1) {
                chmin(ans, dp[i][j-1] + c + a[i][j]);
                chmin(dp[i][j], dp[i][j-1] + c);
            }
        }
        rep(i,h) reverse(a[i].begin(), a[i].end());
    }
    cout << ans << endl;
    return 0;
}