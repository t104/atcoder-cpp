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
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    rep(i,n) cin >> a[i];
    rep(i,n-1) l[i+1] = gcd(l[i], a[i]);
    for (int i = n-1; 0 < i; --i) r[i-1] = gcd(r[i], a[i]);
    int ans = 1;
    rep(i,n) chmax(ans, gcd(l[i], r[i]));
    cout << ans << endl;

    return 0;
}