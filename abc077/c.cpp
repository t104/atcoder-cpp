#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    rep(i,n) {
        int na = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int nc = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
        // printf("%d %d\n", na, nc);
        ans += (ll) na * (n - nc);
    }

    cout << ans << endl;
    return 0;
}