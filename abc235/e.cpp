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

int n, m, q;

struct edge {
    int from, to, w;
    int id = -1;
    edge(int from, int to, int w) : from(from), to(to), w(w) {}
    edge(int from, int to, int w, int id) : from(from), to(to), w(w), id(id) {}
    bool operator<(const edge &other) const {
        return w < other.w;
    }
    bool operator>(const edge &other) const {
        return other.w < w;
    }
};

int main() {
    cin >> n >> m >> q;
    priority_queue<edge, vector<edge>, greater<edge>> que;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        que.emplace(a, b, c);
    }
    rep(i,q) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        que.emplace(u, v, w, i);
    }
    vector<bool> ans(q);
    dsu uf(n);
    while (!que.empty()) {
        edge e = que.top(); que.pop();
        if (0 <= e.id) {
            ans[e.id] = !uf.same(e.from, e.to);
        } else if (!uf.same(e.from, e.to)) {
            uf.merge(e.from, e.to);
        }
    }
    rep(i,q) cout << (ans[i] ? "Yes" : "No") << endl;
    return 0;
}

