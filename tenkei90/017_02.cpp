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
    vector<vector<int>> edge(n);
    rep(i,m) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (r < l) swap(l, r);
        edge[l].push_back(r);
    }

    rep(i,n) sort(edge[i].begin(), edge[i].end());

    ll ans = 0;
    rep(i,n) {
        for (auto j: edge[i]) {
            for (int k = i+1; k < j; ++k) {
                ll r = edge[k].size() - (upper_bound(edge[k].begin(), edge[k].end(), j) - edge[k].begin());
                ll l = lower_bound(edge[k].begin(), edge[k].end(), i) - edge[k].begin();
                ans += l + r;
            }
        }
    }

    cout << ans << endl;
    return 0;
}