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

const int MX = 100010;

int n;
vector<vector<int>> g(MX);
vector<P> eular_tour;
vector<int> first_appear(MX, -1);

P op (P x, P y) {
    return x.first < y.first ? x : y;
}

P e () {
    return {INF, INF};
}

segtree<P, op, e> seg;

void dfs(int v, int p, int d) {
    eular_tour.emplace_back(d, v);
    if (first_appear[v] == -1) first_appear[v] = eular_tour.size() - 1;
    for (auto nv: g[v]) {
        if (nv == p) continue;
        dfs(nv, v, d+1);
        eular_tour.emplace_back(d, v);
    }
}

P lca(int u, int v) {
    int l = first_appear[u];
    int r = first_appear[v];
    if (r < l) swap(l, r);
    P res = seg.prod(l, r+1);
    return res;
}

int depth(int v) {
    return eular_tour[first_appear[v]].first;
}

void solve() {
    int vn;
    cin >> vn;
    vector<int> v(vn);
    for (auto &vi: v) {
        cin >> vi;
        vi--;
    }
    sort(v.begin(), v.end(), [&](auto x, auto y){
        return first_appear[x] < first_appear[y];
    });
    int ans = 0;
    rep(i, vn) {
        int ui = v[i];
        int vi = v[(i+1)%vn];
        int ad = lca(ui, vi).first;
        int ud = depth(ui);
        int vd = depth(vi);
        // printf("%d %d %d\n",ui, vi, ud + vd - 2*ad);
        ans += ud + vd - 2*ad;
    }
    cout << ans/2 << endl;
}

int main() {
    cin >> n;
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q;
    cin >> q;

    int x = 0;
    dfs(0, -1, 0);
    seg = segtree<P, op, e>(eular_tour);

    while (q--) solve();
    return 0;
}