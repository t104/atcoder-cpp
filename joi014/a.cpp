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
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    rep(i,m) cin >> p[i];
    rep(i,m) p[i]--;
    vector<int> a(n-1), b(n-1), c(n-1);
    rep(i,n-1) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<int> cnt(n);
    rep(i,m-1) {
        int from = p[i];
        int to = p[i+1];
        if (to < from) swap(from, to);
        cnt[from]++;
        cnt[to]--;
    }
    rep(i,n-1) {
        cnt[i+1] += cnt[i];
    }

    ll ans = 0;
    rep(i,n-1) {
        ans += min((ll) a[i]*cnt[i], (ll) b[i]*cnt[i] + c[i]);
    }
    cout << ans << endl;
    return 0;
}