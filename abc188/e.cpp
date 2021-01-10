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

int n, m;
vector<ll> a, mi;
vector<vector<int>> g;
ll ans;

void dfs(int v, ll minimum) {
    if (minimum != LINF && mi[v] <= minimum) return;
    if (minimum != LINF) {
        chmax(ans, (ll) a[v] - minimum);
    }
    chmin(minimum, a[v]);
    chmin(mi[v], minimum);
    for (auto nv : g[v]) {
        dfs(nv, minimum);
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    mi.resize(n, LINF);
    g.resize(n);
    rep(i,n) cin >> a[i];
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }

    ans = -LINF;
    rep(i,n) {
        dfs(i,LINF);
    }
    cout << ans << endl;
    return 0;
}