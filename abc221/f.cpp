// https://youtu.be/wMibKG0HyCc

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
using mint = modint998244353;

int n, N;
vector<int> edge[440000];
vector<int> dist;
vector<int> parent;
int D;
int dp[440000];

void dfs(int x, int last = -1) {
    if (last == -1) dist[x] = 0;
    else parent[x] = last;
    for (auto to: edge[x]) {
        if (to == last) continue;
        dist[to] = dist[x] + 1;
        dfs(to, x);
    }
}

void dfs2(int x, int last = -1) {
    if (last == -1) dist[x] = 0;
    else parent[x] = last;
    if (dist[x] == D / 2) dp[x] = 1;
    for (auto to: edge[x]) {
        if (to == last) continue;
        dist[to] = dist[x] + 1;
        dfs2(to, x);
        dp[x] += dp[to];
    }
}

int main() {
    cin >> n;
    N = n + (n - 1);
    dist.resize(N);
    parent.resize(N);
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edge[u].push_back(n+i);
        edge[n+i].push_back(u);
        edge[v].push_back(n+i);
        edge[n+i].push_back(v);
    }

    dfs(0);
    int farest = max_element(dist.begin(), dist.end()) - dist.begin();
    dfs(farest);
    int farest2 = max_element(dist.begin(), dist.end()) - dist.begin();
    int now = farest2;
    D = dist[farest2];
    rep(i, D / 2) now = parent[now];
    int center = now;

    dfs2(center);
    mint ans = 1;
    for (auto neighb: edge[center]) {
        ans *= dp[neighb] + 1;
    }
    ans -= 1;
    ans -= dp[center];

    cout << ans.val() << endl;
    return 0;
}
