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

struct Edge {
    int w, u, v;
    Edge(int w=0, int u=0, int v=0) : w(w), u(u), v(v) {}
    const bool operator<(Edge &rhs) {
        return w < rhs.w;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = Edge(c, a-1, b-1);
    }

    sort(edges.begin(), edges.end());

    
    vector<int> weight;
    dsu uf(n);
    rep(i,m) {
        auto [w, u, v] = edges[i];
        if (uf.same(u,v)) continue;
        weight.push_back(w);
        uf.merge(u, v);
    }
    
    int wn = weight.size();
    ll res = 0;
    rep(i, wn - k + 1) {
        res += weight[i];
    }

    cout << res << endl;
    return 0;
}