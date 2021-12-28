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

ll dp[1<<10];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,1<<n) {
        dp[i] = LINF;
    }
    dp[0] = 0;
    rep(i,m) {
        string s;
        ll c;
        cin >> s >> c;
        int flg = 0;
        rep(j,n) {
            flg |= (s[j] == 'Y') << j;
        }
        rep(j, 1<<n) {
            chmin(dp[j|flg], dp[j] + c);
        }
    }
    ll ans = dp[(1<<n) - 1] == LINF ? -1 : dp[(1<<n) - 1];
    cout << ans << endl;
    return 0;
}

