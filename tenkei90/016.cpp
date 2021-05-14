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

const int MX = 10000;

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    
    ll ans = INF;
    for (ll i = 0; i < MX; ++i) {
        for (ll j = 0; j < MX; ++j) {
            ll s = i*a + j*b;
            if (n < s) break;
            if ((n-s)%c == 0) {
                chmin(ans, i+j+(n-s)/c);
            }
        }
    }

    cout << ans << endl;
    return 0;
}