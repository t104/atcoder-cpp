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
    int to, use;
    edge(int to): to(to) {
        use = 0;
    }
};

vector<int> h;
vector<vector<edge>> edges;
vector<int> use;
int ans;

int dfs1(int v, int p) {
    int tot = 0;
    for (auto &[to, use]: edges[v]) {
        if (to == p) continue;
        int now = dfs1(to, v);
        tot += now;
        if (0 < now) {
            use = 1;
        }
    }
    tot += h[v];
    return tot;
}

void dfs2(int v, int p) {
    for (auto &[to, use]: edges[v]) {
        if (to == p) continue;
        if (use) {
            ans++;
            dfs2(to, v);
        }
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    --x;
    h.resize(n);
    edges.resize(n);
    use.resize(n);
    rep(i,n) cin >> h[i];
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
    ans = 0;
    dfs1(x, -1);
    dfs2(x, -1);
    ans *= 2;
    cout << ans << endl;
    return 0;
}