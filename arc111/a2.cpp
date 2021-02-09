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

ll modPow(ll a, ll x, ll mod) {
    ll res = 0;
    if (x == 1) {
        return a % mod;
    }
    if (x%2 == 0) {
        res = modPow(a, x/2, mod);
        res *= res;
        res %= mod;
        return res;
    }
    res = modPow(a, x-1, mod);
    res *= a;
    res %= mod;
    return res;
}

using mint = modint;

int main() {
    ll n, m;
    cin >> n >> m;
    mint::set_mod(m*m);
    mint ans = 10;
    ans = ans.pow(n);
    cout << ans.val() / m << endl;
    return 0;
}