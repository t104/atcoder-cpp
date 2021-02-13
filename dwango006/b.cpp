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
using P = pair<int,int>;

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<mint> dp(n);
    mint ans = 0;
    rep(i,n-1) {
        dp[i+1] = dp[i] +  (mint (i+1)).inv();
        ans += dp[i+1] * (x[i+1] - x[i]);
    }
    for (int i = 1; i < n; ++i) {
        ans *= i;
    }
    cout << ans.val() << endl;
    return 0;
}