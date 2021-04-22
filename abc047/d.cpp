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
    int n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> mx(n);


    mx[n-1] = a[n-1];
    for (int i = n-2; 0 <= i; --i) {
        mx[i] = mx[i+1];
        chmax(mx[i], a[i]);
    }

    ll pmx = 0;
    int ans = 0;
    rep(i,n) {
        if (chmax(pmx, mx[i]-a[i]))
            ans = 1;
        else if (pmx == mx[i]-a[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}