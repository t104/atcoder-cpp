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

ll comb(int s) {
    return (ll) s*(s-1)/2;
}

int main() {
    int n, m;
    cin >> n >> m;
    dsu uf = dsu(n);
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<ll> ans(m);
    ans[m-1] = (ll) n*(n-1)/2;
    for (int i = m-1; 0 < i; --i) {
        ans[i-1] = ans[i];
        if (uf.same(a[i], b[i])) continue;
        ans[i-1] += comb(uf.size(a[i])) + comb(uf.size(b[i]));
        uf.merge(a[i], b[i]);
        ans[i-1] -= comb(uf.size(a[i]));
    }

    rep(i,m) {
        cout << ans[i] << endl;
    }
    return 0;
}