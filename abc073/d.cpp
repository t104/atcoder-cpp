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
using P = pair<int,int>;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> p(r);
    vector<vector<int>> dp(n, vector<int>(n, INF));
    rep(i,r) {
        cin >> p[i];
        p[i]--;
    }
    rep(i,m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        dp[u][v] = c;
        dp[v][u] = c;
    }

    rep(i,n) dp[i][i] = 0;
    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = INF;
    sort(p.begin(), p.end());
    do {
        int d = 0;
        rep(i,r-1) {
            d += dp[p[i]][p[i+1]];
        }
        chmin(ans, d);
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}