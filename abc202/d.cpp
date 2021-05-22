#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
// template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

vector<vector<int>> children, li;
vector<int> in, out, depth;
int timer;

void dfs(const int u) {
    in[u] = timer++;
    li[depth[u]].push_back(in[u]);
    for (const int v: children[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    out[u] = timer++;
}

int main() {
    int n;
    cin >> n;
    children = li = vector<vector<int>>(n);
    in = out = depth = vector<int>(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        children[p-1].push_back(i);
    }
    dfs(0);

    int q;
    cin >> q;
    while (q--) {
        int u, d;
        cin >> u >> d;
        --u;
        const auto &v = li[d];
        cout << lower_bound(v.cbegin(), v.cend(), out[u]) - lower_bound(v.cbegin(), v.cend(), in[u]) << endl;
    }
    return 0;
}