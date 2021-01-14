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

using mint = modint1000000007;

int n;
mint ans;
vector<vector<int>> g;

int dfs(int v, int p = -1) {
    int res = 1;
    vector<int> ts;
    for (auto nv : g[v]) {
        if (nv == p) continue;
        int t = dfs(nv, v);
        res += t;
        ts.push_back(t);
    }
    if (p != -1) {
        ts.push_back(n-res);
    }
    mint now = mint(2).pow(n-1) - 1;
    cerr << v << ": ";
    for (auto t : ts) {
        cerr << t << ' ';
        now -= mint(2).pow(t) - 1;
    }
    cerr << endl;
    ans += now;
    return res;
}

int main() {
    cin >> n;
    g.resize(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    ans *= mint(2).pow(n).inv();
    cout << ans.val() << endl;
    return 0;
}