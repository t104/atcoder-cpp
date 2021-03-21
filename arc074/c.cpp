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
    ll h, w;
    cin >> h >> w;
    if (h%3 == 0 || w%3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = min(h,w);
    for (ll i = 1; i < w; ++i) {
        ll h1 = h/2;
        ll h2 = h-h1;
        chmin(ans,
        max({i*h, (w-i)*h1, (w-i)*h2}) - min({i*h, (w-i)*h1, (w-i)*h2}));
    }
    for (ll i = 1; i < h; ++i) {
        ll w1 = w/2;
        ll w2 = w-w1;
        chmin(ans,
        max({i*w, (h-i)*w1,(h-i)*w2}) - min({i*w, (h-i)*w1,(h-i)*w2}));
    }
    cout << ans << endl;
    return 0;
}