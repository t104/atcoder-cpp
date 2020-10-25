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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<ll> sum(n-1);
    rep(i,n-1) sum.at(i) = (ll) a.at(i) + a.at(i+1);
    ll ans = 0;
    rep(i,n-1) {
        if (x < sum.at(i)) {
            ll d = (ll) sum.at(i) - x;
            ans += d;
            if (i < n-2) {
                sum.at(i+1) -= min((ll) a.at(i+1), d);
            }
        }
    }
    cout << ans << endl;
    return 0;
}