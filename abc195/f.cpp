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

const int n = 20;
const int n2 = 1<<n;
const vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

int main() {
    ll a, b;
    cin >> a >> b;
    vector<ll> dp(n2);
    dp[0] = 1;
    for (ll x = a; x <= b; ++x) {
        int s = 0;
        rep(i,n) if (x%p[i] == 0) s |= 1<<i;
        rep(i,n2) {
            if (i&s) continue;
            dp[i|s] += dp[i];
        }
    }
    ll ans = 0;
    rep(i,n2) ans += dp[i];
    cout << ans << endl;
    return 0;
}