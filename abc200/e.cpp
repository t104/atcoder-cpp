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

ll c2(ll x) {
    if (x == 0) return 1LL;
    return x*(x-1)/2;
}

int main() {
    ll n, k;
    cin >> n >> k;
    n--;
    ll s = 0;
    while (true) {
        ll d = c2(s+2);
        if (k-d < 0) break;
        k -= d;
        s++;
    }

    ll a = max(0LL, s-2*n);
    while (true) {
        ll d = s+1-a;
        if (k-d < 0) break;
        k -= d;
        a++;
    }
    s -= a;
    ll b = k-1;
    ll c = s-b;
    ++a, ++b, ++c;
    printf("%lld %lld %lld\n", a, b, c);
    return 0;
}