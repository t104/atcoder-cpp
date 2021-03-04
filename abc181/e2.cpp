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
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), w(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> w[i];
    vector<ll> s1(n+1), s2(n+1);
    sort(h.begin(), h.end());
    rep(i,n) {
        if (i%2 == 0) s1[i+1] = s1[i] + h[i];
        else s1[i+1] = s1[i] - h[i];
        if (i%2 == 1) s2[i+1] = s2[i] + h[i];
        else s2[i+1] = s2[i] - h[i];
    }
    ll ans = LINF;
    rep(i,m) {
        int x = lower_bound(h.begin(), h.end(), w[i]) - h.begin();
        ll sum = s2[x] + s1[n] - s1[x];
        if (x%2 == 0) sum -= w[i];
        else sum += w[i];
        chmin(ans,sum);
    }
    cout << ans << endl;
    return 0;
}