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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    int m = n/2;

    // n が偶数のとき、
    // ans = -2*(a[0] + a[1] ... + a[m-2]) - a[m-1] + a[m] + 2*(a[m+1] + a[m+2] ... + a[n-1])
    if (n%2 == 0) {
        rep(i,m-1) ans -= 2*a[i];
        for (int i = m+1; i < n; ++i) ans += 2*a[i];
        ans += a[m] - a[m-1];
        cout << ans << endl;
        return 0;
    }

    // n が奇数のとき次の ans1, ans2 のうち大きいほう
    // ans1 = -2*(a[0] + a[1] + ... + a[m-2]) - a[m-1] -a[m] + 2*(a[m+1] + a[m+2] ... + a[n-1])
    // ans2 = -2*(a[0] + a[1] + ... + a[m-1]) + a[m] + a[m+1] + 2*(a[m+2] + a[m+3] ... + a[n-1])
    rep(i,m-1) ans -= 2*a[i];
    ans -= a[m-1] + a[m];
    for (int i = m+1; i < n; ++i) ans += 2*a[i];
    chmax(ans, ans - a[m-1] + 2*a[m] - a[m+1]);
    cout << ans << endl;

    return 0;
}