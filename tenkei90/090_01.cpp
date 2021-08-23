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

using mint = modint998244353;

int main() {
    ll n, k;
    cin >> n >> k;
    assert(k == 1);
    vector<vector<mint>> dp(n, vector<mint>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout << (dp[n-1][0] + dp[n-1][1]).val() << endl;
    return 0;
}