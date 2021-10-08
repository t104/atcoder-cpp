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

vector<vector<int>> edges;
vector<int> h, go, back;

int ans;

void dfs(int v, int p, int &hoseki, int &d) {
    go[v] = d;
    hoseki += h[v];
    for (auto nv: edges[v]) {
        if (nv == p) continue;
        int hoseki_now = hoseki;
        int d_now = d;
        d++;
        dfs(nv, v, hoseki, d);
        if (hoseki_now == hoseki) {
            ans += d - d_now;
        }
    }
    back[v] = d;
    d++;
}

int main() {
    int n, x;
    cin >> n >> x;
    --x;
    h.resize(n);
    go.resize(n);
    back.resize(n);
    edges.resize(n);
    rep(i,n) cin >> h[i];
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ans = 0;
    int hoseki = 0, d = 0;
    dfs(x, -1, hoseki, d);
    cout << back[x] - go[x] - ans << endl;
    return 0;
}