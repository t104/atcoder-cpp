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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    ll p = 1;
    int l = 0, r = 0;
    rep(i,n) {
        if (a[i] == 0) {
            cout << n << endl;
            return 0;
        }
    }
    while (l < n && r < n) {
        while (r < n) {
            p *= a[r];
            ++r;
            if (p <= k) chmax(ans, r-l);
            else break;
        }
        while (k < p && l < r) {
            p /= a[l];
            ++l;
        }
    }
    cout << ans << endl;
    return 0;
}