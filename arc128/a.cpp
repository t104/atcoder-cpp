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

const double EPS = 1e-6;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll mx = 0, mi = LINF;
    int mxi = -1, mii = -1;
    vector<int> ans(n);
    rep(i,n) {
        if (mi < LINF && mi < a[i]) {
            ans[mxi] = 1;
            ans[mii] = 1;
            mx = 0, mi = LINF;
            mxi = -1, mii = -1;
        }
        if (chmax(mx, a[i])) {
            mxi = i;
            continue;
        }
        if (0 < mx && chmin(mi, a[i])) mii = i;
    }
    if (0 <= mxi && 0 <= mii) {
        ans[mxi] = 1;
        ans[mii] = 1;
    }
    rep(i,n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}

