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

using mint = modint1000000007;

vector<vector<int>> g;
mint ans = 1;
int n, k;

void dfs(int v, int prev, int d1, int d2) {
    ans *= k-d1-d2;
    int sz = g[v].size();
    int j = d1;
    rep(i,sz) {
        int nv = g[v][i];
        if (nv == prev) continue;
        dfs(nv, v, 1, j);
        ++j;
    }
}

int main() {
    cin >> n >> k;
    g.resize(n);
    rep(i,n-1) {




        
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, 0, 0);
    cout << ans.val() << endl;
    return 0;
}