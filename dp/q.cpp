#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 200005;

ll op (ll x, ll y) {
    return max(x,y);
}

ll e () {
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> a[i];
    segtree<ll, op, e> dp(max_n);
    rep(i,n) {
        ll x = dp.prod(0, h[i]) + a[i];
        if (dp.get(h[i]) < x) dp.set(h[i], x);
    }

    cout << dp.all_prod() << endl;
    return 0;
}