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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dsu uf(n);
    vector<int> ans(n);
    int cnt = n;
    for (int i = n-1; 0 <= i; --i) {
        ans[i] = cnt;
        for (auto &v : g[i]) {
            if (i < v) {
                if (!uf.same(i, v)) {
                    cnt--;
                    uf.merge(i, v);
                }
            }
        }
    }
    rep(i,n) cout << ans[i] - (i+1) << endl;
    return 0;
}

