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

int n, ans;
vector<vector<int>> g;
vector<int> visited;

int dfs(int v) {
    if (visited[v]) return 0;
    visited[v] = true;
    vector<int> len = {0};
    for (auto u: g[v]) {
        if (visited[u]) continue;
        len.push_back(dfs(u));
    }
    sort(len.rbegin(), len.rend());
    if (2 <= len.size()) chmax(ans, len[0]+len[1]+1);
    return len[0]+1;
}

int main() {
    cin >> n;
    g.resize(n);
    visited.resize(n, false);
    ans = 0;

    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i,n) dfs(i);
    cout << ans << endl;

    return 0;
}