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

ll dp[105][10005];

int main() {
    int n, x;
    cin >> n >> x;
    rep(i,105) rep(j,10005) dp[i][j] = 0;
    dp[0][0] = 1;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n) rep(j,10005) {
        dp[i+1][j+a[i]] += dp[i][j];
        dp[i+1][j+b[i]] += dp[i][j];
    }
    cout << (0 < dp[n][x] ? "Yes" : "No") << endl;
    return 0;
}

