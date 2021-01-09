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
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n, vector<ll>(n, LINF));
    rep(e, m) {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        --a, --b;
        dp[a][b] = t;
        dp[b][a] = t;
    }
    rep(v, n) dp[v][v] = 0;

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    vector<ll> dp_max(n);
    rep(i,n) {
        rep(j,n) {
            chmax(dp_max[i], dp[i][j]);
        }
    }

    cout << *min_element(dp_max.begin(), dp_max.end()) << endl;

    return 0;
}