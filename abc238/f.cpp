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
mint dp[305][305][305];

int main() {
    int n, k;
    cin >> n >> k;
    vector<P> p(n), q(n);
    rep(i,n) {
        int pi;
        cin >> pi;
        p[i] = make_pair(pi, i);
    }
    rep(i,n) {
        int qi;
        cin >> qi;
        q[i] = make_pair(qi, i);
    }
    sort(p.begin(), p.end());
    vector<int> r(n);
    rep(i,n) {
        r[i] = q[p[i].second].first;
    }
    dp[0][0][n] = 1;
    int mi = INF;
    rep(i1,n) {
        rep(i2,k+1) {
            rep(i3, n+1) {
                if (r[i1] <= i3) dp[i1+1][i2+1][i3] += dp[i1][i2][i3];
                dp[i1+1][i2][min(r[i1], i3)] += dp[i1][i2][i3];
            }
        }
    }
    mint ans = 0;
    rep(i,n+1) ans += dp[n][k][i];
    cout << ans.val() << endl;
    return 0;
}