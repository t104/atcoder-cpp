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
using P = pair<ll,int>;

using mint = modint1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    mint ans = 1;
    int neg = 0, zero = 0, pos = 0;

    if (k == n) {
        rep(i,k) ans *= a[i];
        cout << ans.val() << endl;
        return 0;
    }
    rep(i,n) {
        if (a[i] < 0) neg++;
        else if (a[i] == 0) zero++;
        else pos++;
    }
    if (k%2 == 1 && zero + pos == 0) {
        // negative
        sort(a.rbegin(), a.rend());
        rep(i,k) ans *= a[i];
        cout << ans.val() << endl;
        return 0;
    }
    sort(a.begin(), a.end(), [&](ll x, ll y){
        if (abs(x) == abs(y)) return x < y;
        return abs(y) < abs(x);
    });
    vector<ll> nv, pv;
    for (int i = 0; i < k; ++i) {
        if (a[i] < 0) nv.push_back(a[i]);
        else pv.push_back(a[i]);
    }
    if (nv.size()%2 == 0) {
        rep(i,k) ans *= a[i];
        cout << ans.val() << endl;
        return 0;
    }
    ll ni = LINF, pi = LINF;
    for (int i = k; i < n; ++i) {
        if (a[i] < 0) {
            ni = a[i];
            break;
        }
    }
    for (int i = k; i < n; ++i) {
        if (0 <= a[i]) {
            pi = a[i];
            break;
        }
    }
    if (ni == LINF || pv.size() == 0) {
        nv.pop_back();
        pv.push_back(pi);
    }
    else if (pi == LINF) {
        pv.pop_back();
        nv.push_back(ni);
    }
    else {
        if (abs(ni*nv.back()) < abs(pi*pv.back())) {
            nv.pop_back();
            pv.push_back(pi);
        }
        else {
            pv.pop_back();
            nv.push_back(ni);
        }
    }

    for (auto i: nv) ans *= i;
    for (auto i: pv) ans *= i;

    cout << ans.val() << endl;
    return 0;
}