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

int n;
const int MX = 400005;

vector<bool> visited(MX, false);
vector<vector<int>> g(MX);

void dfs(int v, vector<int> &vs) {
    if (visited[v]) return;
    visited[v] = true;
    vs.push_back(v);
    for (auto vi : g[v]) {
        dfs(vi, vs);
    }
}

int main() {
    cin >> n;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    rep(i,MX) {
        if (visited[i]) continue;
        vector<int> vs;
        dfs(i, vs);
        int vn = vs.size();
        int m = 0;
        for (auto v : vs) {
            m += g[v].size();
        }
        if (m == 2*(vn-1)) ans += vn-1;
        else ans += vn;
    }
    cout << ans << endl;
    return 0;
}