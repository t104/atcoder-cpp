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
    int from, to;
    ll w;
    Edge(int from = 0, int to = 0, ll w = 0) : from(from), to(to), w(w) {}
    bool operator<(Edge &rhs) const {
        return w < rhs.w;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    ll ans = 0;
    rep(i,m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        ans += c;
        edges[i] = Edge(a,b,c);
    }
    sort(edges.begin(), edges.end());
    dsu uf(n);
    for (auto &e: edges) {
        if (e.w < 0 || !uf.same(e.from, e.to)) {
            uf.merge(e.from, e.to);
            ans -= e.w;
        }
    }
    cout << ans << endl;
    return 0;
}

