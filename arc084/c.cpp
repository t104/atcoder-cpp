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
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);
    rep(i,n) cin >> c.at(i);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    rep(i,n) {
        auto pa = lower_bound(a.begin(), a.end(), b.at(i));
        int na = pa - a.begin();
        auto pc = upper_bound(c.begin(), c.end(), b.at(i));
        int nc = c.end() - pc;
        ans += (ll) na * nc;
    }
    cout << ans << endl;
    return 0;
}