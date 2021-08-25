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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b), g[b].push_back(a);
    }
    vector<int> dist(n, INF);
    vector<mint> cnt(n);
    queue<P> que;
    cnt[0] = 1;
    que.emplace(0, 0);
    while (que.size()) {
        auto [v, d] = que.front(); que.pop();
        for (auto &to: g[v]) {
            if (chmin(dist[to], d + 1)) {
                que.emplace(to, d + 1);
                cnt[to] = cnt[v];
            } else if (dist[to] == d + 1) {
                cnt[to] += cnt[v];
            }
        }
    }
    cout << cnt[n-1].val() << endl;
    return 0;
}