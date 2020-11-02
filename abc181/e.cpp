#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const ll LINF = 1LL<<60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), w(m);
    rep(i,n) cin >> h.at(i);
    rep(i,m) cin >> w.at(i);
    sort(h.begin(), h.end());

    ll ans = LINF;
    vector<ll> left(n+1), right(n+1);
    for (int i=2; i<n; i+=2) {
        left.at(i) = left.at(i-2) + h.at(i-1) - h.at(i-2);
        right.at(i) = right.at(i-2) + h.at(n-i+1) - h.at(n-i);
    }
    for (auto wi : w) {
        int i = lower_bound(h.begin(), h.end(), wi) - h.begin();
        if (i%2 == 0) chmin(ans, left.at(i) + right.at(n-i-1) + h.at(i) - wi);
        else chmin(ans, left.at(i-1) + right.at(n-i) + wi - h.at(i-1));
    }
    cout << ans << endl;
    return 0;
}