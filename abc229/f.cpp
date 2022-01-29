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

const int MX = 200010;
/**
 * dp[i][j][k]
 * 頂点 1 の色が j で頂点 i の色が k のときの辺の重さの最小値
 * 
 */
ll dp[MX][2][2];

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,MX) rep(j,2) rep(k,2) dp[i][j][k] = LINF;
    dp[1][0][0] = a[0];
    dp[1][1][1] = 0;
    for (int i = 1; i < n; ++i) {
        rep(j,2) {
            chmin(dp[i+1][j][0], min(dp[i][j][0] + a[i] + b[i-1], dp[i][j][1] + a[i]));
            chmin(dp[i+1][j][1], min(dp[i][j][0], dp[i][j][1] + b[i-1]));
        }
    }
    // 頂点 n と頂点 1 の色が同じとき辺を取り除くことが必要
    rep(i,2) dp[n][i][i] += b[n-1];
    ll ans = LINF;
    rep(i,2) rep(j,2) chmin(ans, dp[n][i][j]);
    cout << ans << endl;
    return 0;
}

