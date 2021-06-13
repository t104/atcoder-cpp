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

using mint = modint1000000007;
using P = pair<mint,mint>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<P> dp(n);
    dp[0].first = 1;
    rep(i,n-1) {
        dp[i+1].first = dp[i].first + dp[i].second;
        dp[i+1].second = dp[i].first;
    }
    mint ans = 0;
    mint tot = dp[n-1].first + dp[n-1].second;
    rep(i,n) {
        mint pos = dp[i].first * (dp[n-i-1].first + dp[n-i-1].second);
        ans += a[i] * (pos + pos - tot);
    }
    cout << ans.val() << endl;
    return 0;
}