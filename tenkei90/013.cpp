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

struct Edge {
    int to, w;
    Edge(int to, int w): to(to), w(w) {}
};

int n, m;
vector<vector<Edge>> g;

vector<int> dijkstra(int v) {
    vector<int> dist(n, INF);
    dist[v] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, v);
    while (que.size()) {
        auto [w, v] = que.top(); que.pop();
        if (dist[v] < w) continue;
        for (auto u: g[v]) {
            int nw = w + u.w;
            if (dist[u.to] <= nw) continue;
            dist[u.to] = nw;
            que.emplace(nw, u.to);
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    rep(i,m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    auto from_s = dijkstra(0);
    auto from_g = dijkstra(n-1);
    rep(i,n) {
        int ans = from_s[i] + from_g[i];
        cout << ans << endl;
    }
    return 0;
}