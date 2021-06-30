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

ll dp[65][1<<20];

int main() {
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    dp[0][0] = 1;
    vector<int> g(d);
    rep(i,d) {
        rep(j,n) {
            if ((a[j]>>i)&1) g[i] |= 1<<j;
        }
    }
    rep(i,d) {
        int flg = g[i];
        rep(s, 1<<n) {
            dp[i+1][s|flg] += dp[i][s];
            dp[i+1][s] += dp[i][s];
        }
    }
    cout << dp[d][(1<<n)-1] << endl;
    return 0;
}