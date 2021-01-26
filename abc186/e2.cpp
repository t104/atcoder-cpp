// https://drken1215.hatenablog.com/entry/2020/12/20/015100

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



ll solve() {
    ll n, s, k;
    cin >> n >> s >> k;
    ll g = gcd(n,k);
    if (s % g) return -1;
    n /= g, s /= g, k /= g;
    modint::set_mod(n);
    modint res = -modint(s) / k;
    return res.val();
}

int main() {
    int t;
    cin >> t;
    rep(i,t) cout << solve() << endl;
    return 0;
}