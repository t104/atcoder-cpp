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

int n, m;
int ans;

int dp[305][305];

int main() {
    cin >> n >> m;
    vector<P> vt;
    rep(i,n) rep(j,n) dp[i][j] = INF;
    rep(i,n) dp[i][i] = 0;
    rep(i,m) {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        if (v < u) swap(u, v);
        if (u == 0) vt.emplace_back(v,l);
        else {
            dp[u][v] = l;
            dp[v][u] = l;
        }
    }

    rep(k,n) rep(i,n) rep(j,n) {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    int ans = INF;
    int p = vt.size();
    rep(i,p) {
        for (int j = i+1; j < p; ++j) {
            chmin(ans, vt[i].second + vt[j].second + dp[vt[i].first][vt[j].first]);
        }
    }

    if (INF <= ans) ans = -1;
    cout << ans << endl;

    return 0;
}