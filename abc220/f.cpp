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

ll n;
vector<vector<int>> g;
vector<int> dist;
vector<ll> children;
vector<ll> ans;

void dfs1(int v, int p, int d) {
    dist[v] = d;
    for (auto nv: g[v]) {
        if (nv == p) continue;
        dfs1(nv, v, d + 1);
        children[v] += children[nv];
    }
}

void dfs2(int v, int p) {
    if (0 < v) {
        ans[v] = ans[p] + n - 2LL * children[v];
    }
    for (auto nv: g[v]) {
        if (nv == p) continue;
        dfs2(nv, v);
    }
}

int main() {
    cin >> n;
    g.resize(n);
    dist.resize(n);
    children.assign(n, 1);
    ans.resize(n);
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, -1, 0);
    rep(i,n) {
        ans[0] += dist[i];
    }
    dfs2(0, -1);
    rep(i,n) cout << ans[i] << endl;
    return 0;
}