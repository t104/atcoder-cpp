#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int n;
vector<ll> h, s;

bool ok(ll x) {
    vector<ll> count(n);
    rep(i,n) {
        if (x < h[i]) return false;
        else {
            count[min((ll) n-1, (x - h[i]) / s[i])]++;
        }
    }
    for (int i = 1; i < n; ++i) count[i] += count[i-1];
    rep(i,n) {
        if (i+1 < count[i]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    h.resize(n), s.resize(n);
    rep(i,n) {
        cin >> h[i] >> s[i];
    }

    // 左側は NG, 右側は OK
    ll l = -1, r = 1e18;
    while (1 < r-l) {
        ll mid = (r+l) / 2;
        
        if (ok(mid)) {
            // mid は OK なので、右側を mid に更新する
            r = mid;
        }
        else {
            // mid は NG なので、左側を mid に更新する
            l = mid;
        }
        printf("%lld %lld\n", l, r);
    }
    cout << r << endl;
    return 0;
}