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

using mint = modint1000000007;

struct Edge{
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

int n;
vector<vector<Edge>> g;

void dfs(int v, int i, int w, vector<int> &dist) {
    dist[v] = w;

    for (auto e: g[v]) {
        int nw = w;
        if ((e.w>>i)&1) nw = (nw+1) % 2;
        if (2 < dist[e.to]) {
            dfs(e.to, i, nw, dist);
        }
    }
}

int main() {
    cin >> n;
    g.resize(n);
    rep(i,n-1) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    mint ans = 0;
    rep(i,61) {
        vector<int> dist(n, INF);
        dfs(0, i, 0, dist);
        int cnt = 0;
        for (auto di: dist) cnt += di;
        ans += mint(2).pow(i) * cnt * (n-cnt);
    }
    cout << ans.val() << endl;
    return 0;
}