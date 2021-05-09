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

ll t, n;

ll f(ll x) {
    return x * (100LL+t) / 100LL;
}

vector<ll> list_all(int x) {
    vector<int> a(x);
    vector<ll> res;
    rep(i,x) a[i] = f(i);
    rep(i,x-1) {
        if (a[i]+1 != a[i+1]) res.push_back(a[i]+1);
    }
    return res;
}

int main() {
    cin >> t >> n;
    ll a = 100LL*n/t;
    if ((100LL*n)%t != 0) a++;
    ll ans = f(a)-1;
    cout << ans << endl;
    // auto all = list_all(1000000);
    // cout << all[n-1] << endl;
    return 0;
}