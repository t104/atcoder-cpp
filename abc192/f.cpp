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
ll dp[MX][MX];

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = LINF;
    for (int k = 1; k <= n; ++k) {
        rep(i,k+1) rep(j,k) dp[i][j] = -LINF;
        dp[0][0] = 0;
        for (int na: a) {
            for (int i = k-1; 0 <= i; --i) {
                rep(j,k) {
                    chmax(dp[i+1][(j+na)%k], dp[i][j]+na);
                }
            }
        }
        ll s = dp[k][x%k];
        if (0 <= s) ans = min(ans, (x-s)/k);
    }

    cout << ans << endl;
    return 0;
}