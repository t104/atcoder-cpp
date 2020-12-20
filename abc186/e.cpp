#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

void solve() {
    ll n, s, k;
    cin >> n >> s >> k;

    ll p = n/k;
    if (0 < n%k) ++p;
    ll l = (k * p) % n;

    ll ans = 0;
    if (l == 0) {
        if ((n-s)%k == 0) {
            cout << (n-s)/k << endl;
        }
        else {
            cout << -1 << endl;
        }
        return;
    }
    if (k <= l) {
        for (int i = 0; i <= n/l + 1; ++i) {
            if ((n-s)%k == 0) {
                ans += (n-s)/k;
                cout << ans << endl;
                return;
            }
            s += l;
        }
    }
    else {
        for (int i = 0; i <= p; ++i) {
            if ((n-s)%l == 0) {
                ans += (n-s)/l;
                cout << ans << endl;
                return;
            }
        }
        s += k;
    }

    cout << -1 << endl;

}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}