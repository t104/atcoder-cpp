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
    vector dp(n+1, vector<mint>(b));
    dp[0][0] = 1;
    rep(i,k) cin >> c[i];
    rep(i,n) {
        rep(j,b) {
            for (auto ci: c) {
                int r = (j * 10 + ci) % b;
                dp[i+1][r] += dp[i][j];
            }
        }
    }
    cout << dp[n][0].val() << endl;
    return 0;
}