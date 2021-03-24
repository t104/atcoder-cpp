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

struct edge {
    int to, d, id;
    edge(int id, int to, int d): id(id), to(to), d(d) {}
};

int dist[100005];
bool check[200005];
vector<vector<edge>> g;
bool ok = true;

void dfs(int v, int d) {
    if (dist[v] == INF) dist[v] = d;
    else if (dist[v] != d) {
        ok = false;
        return;
    } else {
        return;
    }
    for (auto &e: g[v]) {
        if (check[e.id]) continue;
        check[e.id] = true;
        dfs(e.to, d + e.d);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,n) dist[i] = INF;
    g.resize(n);
    dsu uf(n);
    rep(i,m) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        g[l].emplace_back(i, r, d);
        g[r].emplace_back(i, l, -d);
        uf.merge(l,r);
    }
    set<int> leader;
    rep(i,n) {
        int ld = uf.leader(i);
        if (leader.count(ld)) continue;
        leader.insert(ld);
        dfs(i,0);
    }
    cout << (ok ? "Yes": "No") << endl;
    return 0;
}