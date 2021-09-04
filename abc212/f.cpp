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

struct edge {
    int to, s, t;
    edge(int to, int s, int t): to(to), s(s), t(t) {}
};

vector<vector<edge>> g;

void dfs(int x, int y, int z) {
    for (auto &e: g[y]) {
        if (z <= e.s) break;
        if (x <= e.s) {
            if (z <= e.t) {
                cout << y+1 << ' ' << e.to+1 << endl;
                return;
            }
            return dfs(e.t, e.to, z);
        }
    }
    cout << y+1 << endl;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n);
    rep(i,m) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        --a, --b;
        g[a].emplace_back(b, s, t);
    }
    for (auto &edges: g) {
        sort(edges.begin(), edges.end(), [](auto x, auto y){
            return x.s < y.s;
        });
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        dfs(x, y, z);
    }
    return 0;
}