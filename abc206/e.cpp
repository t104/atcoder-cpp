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
    int l, r;
    cin >> l >> r;

    vector<ll> f(r+1);
    ll ans = 0;
    for (int g = r; 2 <= g; --g) {
        ll w = r/g - (l-1)/g;
        f[g] = w*w;
        for (int i = g*2; i <= r; i += g) {
            f[g] -= f[i];
        }
        ans += f[g];
    }

    for (int i = l; i <= r; ++i) {
        if (i == 1) continue;
        ans -= r/i*2-1;
    }

    cout << ans << endl;
    return 0;
}