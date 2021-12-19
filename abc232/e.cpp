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
    ll h, w, x1, y1, x2, y2;
    int k;
    cin >> h >> w >> k;
    cin >> x1 >> y1 >> x2 >> y2;
    mint dp[1<<2];
    int flg = 0;
    if (x1 != x2) flg |= 1<<1;
    if (y1 != y2) flg |= 1;
    dp[flg] = 1;
    rep(i,k) {
        mint tmp[1<<2];
        tmp[0] = dp[1] + dp[2];
        tmp[1] = dp[0] * mint(w - 1) + dp[1] * mint(w - 2) + dp[3];
        tmp[2] = dp[0] * mint(h - 1) + dp[2] * mint(h - 2) + dp[3];
        tmp[3] = dp[1] * mint(h - 1) + dp[2] * mint(w - 1) + dp[3] * mint(h + w - 4);
        swap(dp, tmp);
    }
    cout << dp[0].val() << endl;
    return 0;
}

