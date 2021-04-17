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

int main() {
    int N, C;
    cin >> N >> C;
    vector d(C, vector(C,0));
    vector c(N, vector(N,0));
    rep(i,C) rep(j,C) {
        cin >> d[i][j];
    }
    rep(i,N) rep(j,N) {
        cin >> c[i][j];
        c[i][j]--;
    }
    ll ans = LINF;
    vector dp(3, vector(C,0));
    rep(ci,C) {
        rep(i,N) rep(j,N) {
            if (c[i][j] == ci) continue;
            dp[(i+j)%3][ci] += d[c[i][j]][ci];
        }
    }
    vector col(C,0);
    rep(i,C) col[i] = i;
    rep(i,C) rep(j,C) rep(k,C) {
        if (i==j || j==k || k==i) continue;
        ll sum = 0;
        sum += dp[0][i];
        sum += dp[1][j];
        sum += dp[2][k];
        chmin(ans, sum);
    }
    cout << ans << endl;
    return 0;
}