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

vector<pair<ll,ll>> primeFactorize(ll n) {
    vector<pair<ll,ll>> res;
    for (ll a = 2; a*a <= n; ++a) {
        if (n%a != 0) continue;
        ll ex = 0;
        while (n%a == 0) {
            n /= a;
            ex++;
        }
        res.emplace_back(a, ex);
    }

    if (n != 1) res.emplace_back(n, 1);
    return res;
}

vector<ll> factorList(ll n) {
    vector<ll> res;
    for (ll a = 1; a*a <= n; ++a) {
        if (n%a != 0) continue;
        res.push_back(a);
        ll q = n/a;
        if (q != a) res.push_back(q);
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ans = factorList(n-1).size();
    
    for (auto f: factorList(n)) {
        if (f == 1 || f == n) continue;
        ll r = n;
        while (r%f == 0) r/= f;
        if ((r-1)%f == 0) ans++;
    }

    cout << ans << endl;
    return 0;
}