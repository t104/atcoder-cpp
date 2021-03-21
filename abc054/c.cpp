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

int n, m, ans;
vector<vector<int>> g;
void dfs(int v, int s) {
    s |= 1<<v;
    if (s == (1<<n)-1) {
        ans++;
        return;
    }
    for (auto e: g[v]) {
        if ((s>>e)&1) continue;
        dfs(e,s);
    }
}

int main() {
    cin >> n >> m;
    ans = 0;
    g.resize(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,0);
    cout << ans << endl;
    return 0;
}