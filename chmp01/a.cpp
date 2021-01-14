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
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    rep(i,n) {
        a[i+1] += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ll ans = 0;
        for (int l = 0; i+l < n+1; ++l) {
            chmax(ans, a[i+l] - a[l]);
        }
        cout << ans << endl;
    }
    return 0;
}