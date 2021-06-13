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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    map<ll, ll> mp;
    rep(i,q) {
        ll k;
        cin >> k;
        ll l = 0, r = LINF;
        while (l+1 < r) {
            ll m = (l+r) / 2;
            auto pos = lower_bound(a.begin(), a.end(), m);
            ll cnt = k + pos - a.begin();
            if (m <= cnt) l = m;
            else r = m;
        }
        cout << l << endl;
    }
    return 0;
}