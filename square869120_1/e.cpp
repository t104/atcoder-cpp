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
using mint = modint1000000007;
const int mod = 1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), c(q+2);
    rep(i,n) cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        cin >> c[i];
        c[i]--;
    }
    c[0] = 0, c[q+1] = 0;
    vector<mint> r(n);
    for (int i = 1; i < n; ++i) {
        r[i] = ((mint) a[i-1]).pow(a[i]);
    }
    rep(i,n-1) {
        r[i+1] += r[i];
    }

    // rep(i,n) cout << r[i].val() << endl;

    mint ans = 0;
    rep(i, q+1) {
        int from = c[i];
        int to = c[i+1];
        if (to < from) swap(from, to);
        ans += r[to] - r[from] + (mint) mod;
    }
    cout << ans.val() << endl;
    return 0;
}