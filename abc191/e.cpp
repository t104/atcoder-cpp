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

int n, m;

struct Edge {
    int to, w;
    Edge(int to, int w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;
vector<vector<ll>> dist;
Graph g;

vector<ll> dijkstra(int from) {
    vector<ll> res(n,LINF);
    priority_queue<P,vector<P>,greater<P>> que;
    que.emplace(0,from);
    while(!que.empty()) {
        auto [w, v] = que.top(); que.pop();
        if (res[v] < w) continue;
        for (auto e: g[v]) {
            if (chmin(res[e.to], w + e.w)) {
                que.emplace(w + e.w, e.to);
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    dist.resize(n);
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b,c);
    }
    rep(i,n) dist[i] = dijkstra(i);
    rep(i,n) {
        if (LINF <= dist[i][i]) cout << -1 << endl;
        else cout << dist[i][i] << endl;
    }

    return 0;
}