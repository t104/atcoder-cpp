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

const int MX = 100005;

int main() {
    ll n;
    cin >> n;
    ll ans = n;
    vector<int> a(MX);
    for (ll i = 2; i*i <= n; ++i) {
        if (a[i]) continue;
        ll x = i;
        while(true) {
            x *= i;
            if (n < x) break;
            if (x < MX) a[x] = 1;
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}