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

ll dp[55][55];
ll dp2[55][55];
const ld EPS = 1e-9;

int main() {
    cout << std::fixed << std::setprecision(15);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    dp2[0][0] = 1;
    rep(i,n) {
        rep(j,n) {
            if (dp[i+1][j] == dp[i][j]) {
                dp2[i+1][j] += dp2[i][j];
            } else if (chmax(dp[i+1][j], dp[i][j])) {
                dp2[i+1][j] = dp2[i][j];
            }
            if (dp[i+1][j+1] == dp[i][j] + v[i]) {
                dp2[i+1][j+1] += dp2[i][j];
            } else if (chmax(dp[i+1][j+1], dp[i][j] + v[i])) {
                dp2[i+1][j+1] = dp2[i][j];
            }
        }
    }
    ld ans = 0;
    ll cnt = 0;
    for (ll i = a; i <= b; ++i) {
        ld m = (ld) dp[n][i] / i;
        if (abs(ans - m) < EPS) {
            cnt += dp2[n][i];
        } else if (chmax(ans, m)) {
            cnt = dp2[n][i];
        }
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}