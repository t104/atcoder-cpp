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

mint ans = 0;

int n, m, k;
vector<vector<int>> g;
vector<vector<mint>> dp;

void print_dp() {
    rep(i,k+1) {
        rep(j,n) cout << dp[i][j].val() << ' ';
        cout << endl;
    }
}

int main() {
    cin >> n >> m >> k;
    g.resize(n);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp.resize(k+1, vector<mint>(n));
    dp[0][0] = 1;
    rep(i,k) {
        mint sum = 0;
        rep(j,n) sum += dp[i][j];
        rep(j,n) dp[i+1][j] = sum;
        rep(j,n) {
            dp[i+1][j] -= dp[i][j];
            for (auto v: g[j]) {
                dp[i+1][v] -= dp[i][j];
            }
        }
    }
    // print_dp();
    cout << dp[k][0].val() << endl;
    return 0;
}