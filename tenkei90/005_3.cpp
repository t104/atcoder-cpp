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

using mint = modint1000000007;

int main() {
    int k, b;
    ll n;
    cin >> n >> b >> k;
    vector<int> c(k);
    rep(i,k) cin >> c[i];

    // pow10[i] = 10 ^ (2^i) % b
    vector<int> pow10(64);
    pow10[0] = 10 % b;
    rep(i,63) pow10[i+1] = (pow10[i] * pow10[i]) % b;

    vector dp(64, vector<mint>(b));
    rep(i,k) dp[0][c[i]%b]++;

    rep(i,62) {
        rep(j,b) {
            rep(ki,b) {
                int r = (j * pow10[i] + ki) % b;
                dp[i+1][r] += dp[i][j] * dp[i][ki];
            }
        }
    }
    
    vector ans(64, vector<mint>(b));
    ans[0][0] = 1;
    rep(i,62) {
        if ((n>>i)&1) {
            rep(j,b) {
                rep(ki,b) {
                    int r = (j * pow10[i] + ki) % b;
                    ans[i+1][r] += ans[i][j] * dp[i][ki];
                }
            }
        }
        else {
            rep(j,b) ans[i+1][j] = ans[i][j];
        }
    }
    cout << ans[62][0].val() << endl;
    return 0;
}