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
    vector<vector<int>> g(n);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    rep(i,k) {
        cin >> c[i];
        --c[i];
    }

    vector<vector<int>> dist(k, vector<int>(k));
    rep(i,k) {
        vector<int> d(n, INF);
        queue<int> que;
        que.push(c[i]);
        d[c[i]] = 0;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (auto nv : g[v]) {
                if (d[nv] != INF) continue;
                    d[nv] = d[v] + 1;
                    que.push(nv);
            }
        }
        rep(j,k) dist[i][j] = d[c[j]];
    }
    
    vector<vector<int>> dp(1<<k, vector<int>(k, INF));
    rep(i,k) dp[1<<i][i] = 1;
    rep(s,1<<k) {
        rep(i,k) {
            if (~s>>i&1) continue;
            rep(j,k) {
                if (s>>j&1) continue;
                chmin(dp[s|(1<<j)][j], dp[s][i] + dist[i][j]);
            }
        }
    }
    
    int ans = INF;
    rep(i,k) chmin(ans, dp[(1<<k)-1][i]);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}