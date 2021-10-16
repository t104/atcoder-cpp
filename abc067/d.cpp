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

int n;
vector<vector<int>> g;
vector<int> dist_fen, dist_snk;

void dfs(int v, int p, vector<int> &depth) {
    for (auto nv: g[v]) {
        if (nv == p) continue;
        depth[nv] = depth[v] + 1;
        dfs(nv, v, depth);
    }
}

int main() {
    cin >> n;
    g.resize(n);
    dist_fen.resize(n);
    dist_snk.resize(n);
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, dist_fen);
    dfs(n-1, -1, dist_snk);
    int fen = 0, snk = 0;
    rep(i,n) {
        if (dist_fen[i] <= dist_snk[i]) fen++;
        else snk++;
    }
    if (snk < fen) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}