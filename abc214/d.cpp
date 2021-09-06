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

struct edge {
    int from, to;
    ll w;
    edge(int from, int to, ll w): from(from), to(to), w(w) {}
};

int main() {
    int n;
    cin >> n;
    vector<edge> edges;
    rep(i,n-1) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(u, v, w);
    }
    sort(edges.begin(), edges.end(), [&](auto &lhs, auto &rhs) {
        return lhs.w < rhs.w;
    });
    dsu uf(n);
    ll ans = 0;
    for (auto e: edges) {
        ans += e.w * uf.size(e.from) * uf.size(e.to);
        uf.merge(e.from, e.to);
    }
    cout << ans << endl;
    return 0;
}