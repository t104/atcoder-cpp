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
using Pint = pair<int,int>;

int N, M;
int P[1000];
set<Pint> G[1000];
vector<int> ans;
bool vis[1000];
bool usd[1000];

bool dfs(int u, int to) {
    if (u == to) return true;
    vis[u] = true;
    for (auto e : G[u]) {
        int v = e.first;
        if (vis[v]) continue;
        ans.push_back(e.second);
        swap(P[u], P[v]);
        if (dfs(v, to)) return true;
        swap(P[u], P[v]);
        ans.pop_back();
    }
    return false;
}


int main() {
    cin >> N;
    rep(i,N) cin >> P[i], P[i]--;
    cin >> M;
    dsu uf(N);
    rep(i,M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        // 同じ連結成分にあるときは無視して、グラフが必ず木になるようにする
        if (!uf.same(a, b)) {
            G[a].insert({b, i+1});
            G[b].insert({a, i+1});
            uf.merge(a, b);
        }
    }

    rep(_, N) {
        int mid = -1;
        // 葉を探して mid とする
        rep(i,N) {
            if (!usd[i]) {
                if (mid == -1 || G[i].size() == 1) mid = i;
            }
        }
        // P[mid] に移動する数 mid + 1 のある場所を from とする
        int from = 0;
        while (P[from] != mid) from++;
        rep(j, N) vis[j] = false;
        // from から mid へ移動するようにスワップする
        if (!dfs(from, mid)) {
            cout << -1 << endl;
            return 0;
        }
        // P[mid] は並べ替え済みになったので、
        // P[mid] へ向かう辺を消去する
        for (auto &[v, idx] : G[mid]) {
            G[v].erase(make_pair(mid, idx));
        }
        usd[mid] = true;
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] << (i+1 == ans.size() ? "\n" : " ");
    }
    return 0;
}