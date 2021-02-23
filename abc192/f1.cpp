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

const int MX = 101;
ll dp[MX][MX][MX];

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll ans = LINF;
    for (int mod = 1; mod <= n; ++mod) {
        rep(i,n+1) rep(j,mod+1) rep(k,mod) dp[i][j][k] = -LINF;
        for (int i = 0; i < n; ++i) {
            dp[i][0][0] = 0;
            for (int j = 0; j <= mod; ++j) {
                for (int k = 0; k < mod; ++k) {
                    chmax(dp[i+1][j][k], dp[i][j][k]);
                    chmax(dp[i+1][j+1][(k+a[i])%mod], dp[i][j][k] + a[i]);
                }
            }
        }
        
        ll s = dp[n][mod][x%mod];
        if (0 <= s)
            chmin(ans, (x-s)/mod);
    }

    cout << ans << endl;

    return 0;
}