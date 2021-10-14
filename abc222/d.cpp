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
const int MX = 3010;

mint dp[MX][MX];

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    dp[0][0] = 1;
    rep(i,n) {
        rep(j,3000) {
            dp[i][j+1] += dp[i][j];
        }
        for (int j = a[i]; j <= b[i]; ++j) {
            dp[i+1][j] += dp[i][j];
        }
    }
    mint ans = 0;
    rep(i,3001) {
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
    return 0;
}

