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

int n;
vector<vector<int>> g;
vector<int> c;
vector<int> ans;
vector<int> col(100005);


void dfs(int v, int prev) {
    if (ans[v] != -1) {
        return;
    }
    if (col[c[v]] == 0) ans[v] = 1;
    else ans[v] = 0;
    col[c[v]]++;
    for (auto nv: g[v]) {
        if (nv == prev) continue;
        dfs(nv, v);
    }
    col[c[v]]--;
}

int main() {
    cin >> n;
    g.resize(n);
    c.resize(n);
    ans.resize(n,-1);
    rep(i,n) cin >> c[i];
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    rep(i,n) {
        if (ans[i] == 1) {
            cout << i+1 << endl;
        }
    }
    return 0;
}