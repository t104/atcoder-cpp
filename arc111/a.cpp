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

ll modPow(ll a, ll n, ll p) {
    if (n == 0) return 0;
    if (n == 1) return a%p;
    if (n%2 == 1) return (a * modPow(a, n-1, p)) % p;
    ll t = modPow(a, n/2, p);
    return (t*t) % p;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll res = modPow(10, n, m*m);
    res = (res/m) % m;
    cout << res << endl;
    return 0;
}