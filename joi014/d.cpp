#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int MX = 1005;
ll dp[MX][MX];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n), c(m);
    rep(i,n) cin >> d[i];
    rep(i,m) cin >> c[i];
    rep(i,MX) rep(j,MX) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,m) {
        rep(j,n+1) {
            chmin(dp[i+1][j+1], dp[i][j] + c[i]*d[j]);
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}