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
using P = pair<ll,int>;

struct Edge {
    int from, to;
    ll w;
    Edge(int from = 0, int to = 0, ll w = 0) : from(from), to(to), w(w) {}
    bool operator<(Edge &rhs) const {
        return w < rhs.w;
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<P> xs(n), ys(n);
    rep(i,n) {
        xs[i] = make_pair(x[i], i);
        ys[i] = make_pair(y[i], i);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    vector<Edge> edges(n);
    rep(i,n-1) {
        int from = xs[i].second;
        int to = xs[i+1].second;
        ll w = abs(xs[i+1].first - xs[i].first);
        edges.emplace_back(from, to, w);
    }
    rep(i,n-1) {
        int from = ys[i].second;
        int to = ys[i+1].second;
        ll w = abs(ys[i+1].first - ys[i].first);
        edges.emplace_back(from, to, w);
    }
    
    sort(edges.begin(), edges.end());
    
    ll res = 0;
    dsu uf(n);
    for (auto e : edges) {
        if (uf.same(e.from, e.to)) continue;
        res += e.w;
        uf.merge(e.from, e.to);
    }
    cout << res << endl;
    return 0;
}