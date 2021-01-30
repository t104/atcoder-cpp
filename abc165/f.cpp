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

const int MX = 200005;

vector<int> a(MX), lis(MX, INF), ans(MX);
vector<vector<int>> g(MX);

void dfs(int v) {
    for (auto nv : g[v]) {
        if (0 < ans[nv]) continue;
        auto itr = lower_bound(lis.begin(), lis.end(), a[nv]);
        int prev = *itr;
        ans[nv] = max(int (itr - lis.begin()), ans[v]);
        *itr = a[nv];
        dfs(nv);
        *itr = prev;
    }
}

int main() {
    int n;
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lis[0] = -INF;
    lis[1] = a[0];
    ans[0] = 1;
    dfs(0);
    rep(i,n) {
        cout << ans[i] << endl;
    }
    return 0;
}