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

int n;
vector<vector<int>> g;
vector<mint> dp;
const int MX = 200010;

P dfs(int v, int p) {
    P res = {1, 1};
    map<int, int> depth;
    for (auto nv: g[v]) {
        if (nv == p) continue;
        P p = dfs(nv, v);
        depth[p.first] += p.second;
        p.first++;
        if (res.first < p.first) {
            res = {p.first, 1};
        } else if (res.first == p.first) {
            res.second++;
        }
    }
    
    return res;
}

int main() {
    cin >> n;
    g.resize(n);
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    int x = 0;

    return 0;
}

