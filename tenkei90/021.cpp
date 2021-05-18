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

using Graph = vector<vector<int>>;

vector<bool> visited1, visited2;
stack<int> hist;

void dfs1(Graph &g, int v) {
    visited1[v] = true;
    
    for (auto nv: g[v]) {
        if (visited1[nv]) continue;
        dfs1(g, nv);
    }

    hist.push(v);
}

void dfs2(Graph &g, int v, ll &cnt) {
    visited2[v] = true;
    cnt++;

    for (auto nv: g[v]) {
        if (visited2[nv]) continue;
        dfs2(g, nv, cnt);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n), rg(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    visited1.assign(n, false);
    visited2.assign(n, false);

    ll ans = 0;
    rep(i,n) {
        if (visited1[i]) continue;
        dfs1(g, i);
    }
    while (!hist.empty()) {
        int v = hist.top(); hist.pop();
        if (visited2[v]) continue;
        ll cnt = 0;
        dfs2(rg, v, cnt);
        ans +=  cnt*(cnt-1)/2;
    }
    cout << ans << endl;
    return 0;
}