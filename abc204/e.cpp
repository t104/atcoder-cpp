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
using P = pair<ll,int>;

struct Edge {
    int to;
    ll c, d;
    Edge(int to, ll c, ll d): to(to), c(c), d(d) {}

    ll dist(ll t) {
        return t + c + d/(t+1);
    }

    ll bestDist(ll t) {
        ll l = t, r = LINF;
        if (dist(l) < dist(l+1)) return dist(l);
        while (l+1 < r) {
            ll m = (l+r)/2;
            if (dist(m) > dist(m+1)) l = m;
            else r = m;
        }
        return dist(l+1);
    }
};

vector<vector<Edge>> g;
vector<ll> dist;
int n, m;

int main() {
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, LINF);
    dist[0] = 0;
    rep(i,m) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);
    }

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [d, v] = que.top(); que.pop();
        if (dist[v] < d) continue;
        for (auto next: g[v]) {
            ll nd = next.bestDist(d);
            if (dist[next.to] <= nd) continue;
            dist[next.to] = nd;
            que.emplace(nd, next.to);
        }
    }

    if (dist[n-1] == LINF) {
        cout << -1 << endl;
    }
    else {
        cout << dist[n-1] << endl;
    }
    return 0;
}