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
    int n, m;
    cin >> n >> m;
    vector<P> keys(m);
    rep(i,m) {
        cin >> keys[i].first;
        int b;
        cin >> b;
        rep(j,b) {
            int c;
            cin >> c;
            --c;
            keys[i].second |= 1<<c;
        }
    }
    vector<vector<int>> dp(m+1, vector<int>(1<<n, INF));
    dp[0][0] = 0;
    rep(i,m) {
        rep(s,1<<n) {
            chmin(dp[i+1][s], dp[i][s]);
            chmin(dp[i+1][s|keys[i].second], dp[i][s] + keys[i].first);
        }
    }

    int ans = dp[m][(1<<n)-1];
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}