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

const int MX = 405;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(n, LINF));
    rep(i,n) dp[i][i] = 0;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        chmin(dp[a][b], c);
    }
    ll ans = 0;
    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
                ans += dp[i][j] == LINF ? 0 : dp[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}