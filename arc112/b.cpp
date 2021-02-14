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
    ll b, c;
    cin >> b >> c;
    ll ans = 0;
    if (b == 0) {
        ans += 2 * (c/2 + 1) - 1;
        if (c%2 == 0) ans--;
    }
    else if (0 < b) {
        if (0 < b-c/2) {
            ans += 2*(c/2 + 1);
            if (c%2 == 0) ans--;
            ans += (c-1)/2 * 2;
            if (1 < c && (c-1)%2 == 0) ans--;
        }
        else {
            ll l = -b - (c-1)/2;
            ll r = -l;
            if ((c-1)%2 == 0) r--;
            ans += r-l+1;
        }
    }
    else {
        ans += 2 * (c/2 + 1);
        if (c%2 == 0) ans--;
        if (b < -b - (c-1)/2) {
            ans += (c-1)/2;
        }
        else {
            ans += -b-b-1;
        }
    }
    cout << ans << endl;
    return 0;
}