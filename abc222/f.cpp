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

int n, N;
vector<ll> d;

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost): to(to), cost(cost) {}
};

using Graph = vector<vector<Edge>>;
Graph g;

/**
 * LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
 * 前処理: O(nlogn)時間, O(nlogn)空間
 * https://algo-logic.info/lca/
 **/
struct LCA {
    vector<vector<int>> parent;
    vector<int> dist;
    vector<ll> cost;
    LCA(const Graph &G, int root = 0) { init(G, root); }

    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1<<K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        cost.assign(V, 0);
        dfs(G, root, -1, 0, 0);
        for (int k = 0; k + 1 < K; ++k) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k+1][v] = -1;
                } else {
                    parent[k+1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d, ll c) {
        parent[0][v] = p;
        dist[v] = d;
        cost[v] = c;
        for (auto e: G[v]) {
            if (e.to == p) continue;
            dfs(G, e.to, v, d+1, c + e.cost);
        }
    }

    // u と v の LCA を求める。計算量 O(logn)
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int K = parent.size();
        for (int k = 0; k < K; ++k) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = K-1; 0 <= k; --k) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    
};

int main() {
    cin >> n;
    N = 2*n;
    g.resize(N);
    d.resize(N);
    rep(i,n-1) {
        int a, b;
        ll c;
        cin >> a >> b;
        --a, --b;
        cin >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    LCA lca(g);
    return 0;
}

