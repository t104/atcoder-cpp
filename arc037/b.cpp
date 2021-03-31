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
vector<vector<int>> g;
vector<bool> visited;

bool dfs(int v, int prev) {
    if (visited[v]) return false;
    visited[v] = true;
    bool ok = true;
    for (auto nv: g[v]) {
        if (nv == prev) continue;
        ok &= dfs(nv, v);
    }
    return ok;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    visited.resize(n, false);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    rep(i,n) {
        if (!visited[i] && dfs(i, -1)) ans++;
    }
    cout << ans << endl;
    return 0;
}