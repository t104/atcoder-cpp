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
using P = pair<ll,ll>;

int n, m, x, y;

struct Edge {
    int to;
    ll t, k;
    Edge(int to, ll t, ll k): to(to), t(t), k(k) {}
};

vector<vector<Edge>> g;

int main() {
    cin >> n >> m >> x >> y;
    --x, --y;
    g.resize(n);
    rep(i,m) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        --a, --b;
        g[a].emplace_back(b, t, k);
        g[b].emplace_back(a, t, k);
    }

    vector<ll> dist(n, LINF);
    dist[x] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, x);
    while (que.size()) {
        auto [c, v] = que.top();
        que.pop();
        if (dist[v] < c) continue;
        for (auto e: g[v]) {
            ll nc = c;
            if (0 < nc%e.k) nc = (nc/e.k + 1) * e.k;
            nc += e.t;
            if (nc < dist[e.to]) {
                dist[e.to] = nc;
                que.emplace(nc, e.to);
            }
        }
    }
    
    if (dist[y] < LINF) {
        cout << dist[y] << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}