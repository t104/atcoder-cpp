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

int n, u, v;
vector<vector<int>> g;

void dfs(int v, ll d, vector<ll> &dist) {
    if (dist[v] < INF) return;
    dist[v] = d;
    for (auto e: g[v]) {
        dfs(e, d+1, dist);
    }
}

int main() {
    cin >> n >> u >> v;
    --u, --v;
    g.resize(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (g[u].size() == 1 && g[u][0] == v) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dt(n, LINF), da(n, LINF);
    dfs(u, 0, dt);
    dfs(v, 0, da);

    ll ans = 0;
    rep(i,n) {
        if (dt[i] < da[i]) chmax(ans, da[i]);
    }
    cout << ans - 1 << endl;

    return 0;
}