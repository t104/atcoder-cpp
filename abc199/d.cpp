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

int n, m;
vector<vector<int>> g;
vector<bool> visited;


void dfs(int v, vector<int> &member) {
    if (visited[v]) return;
    member.push_back(v);
    visited[v] = true;
    for (auto u: g[v]) {
        dfs(u, member);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    visited.resize(n, false);

    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ans = 1;
    rep(i,n) {
        vector<int> member;
        dfs(i,member);
        int sz = member.size();
        if (sz == 0) continue;
        ll cnt = 0;
        rep(s, 1<<(sz-1)) {
            vector<int> col(n,-1);
            col[member[0]] = 0;
            rep(j,sz-1) {
                for (auto u: g[member[j+1]]) {
                    if (col[u] != -1) {
                        if ((s>>j)&1)
                            col[member[j+1]] = (col[u]+2)%3;
                        else 
                            col[member[j+1]] = (col[u]+1)%3;
                        break;
                    }
                }
            }
            bool ok = true;
            for (auto u: member) {
                for (auto v: g[u]) {
                    if (col[u] == col[v]) ok = false;
                }
            }
            if (ok) cnt++;
        }
        ans *= 3LL*cnt;
    }
    cout << ans << endl;
    return 0;
}