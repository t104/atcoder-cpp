#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(), a.end());
    ll ans = 0;
    int p = n/2;
    if (n%2 == 0) {
        rep(i,p-1) ans -= 2 * a.at(i);
        ans -= a.at(p-1);
        ans += a.at(p);
        for (int i = p+1; i < n; ++i) ans += 2 * a.at(i);
    }
    else {
        ll ans1 = 0;
        rep(i,p) ans1 -= 2 * a.at(i);
        ans1 += a.at(p);
        ans1 += a.at(p+1);
        for (int i = p+2; i < n; ++i) ans1 += 2 * a.at(i);
        chmax(ans, ans1);

        ll ans2 = 0;
        rep(i,p-1) ans2 -= 2* a.at(i);
        ans2 -= a.at(p-1);
        ans2 -= a.at(p);
        for (int i = p+1; i < n; ++i) ans2 += 2 * a.at(i);
        chmax(ans, ans2);
    }
    cout << ans << endl;
    return 0;
}