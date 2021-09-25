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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int> cb(n), cc(n);
    rep(i,n) {
        int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (idx < n) cb[idx] += 1;
    }
    int cnt = 0;
    rep(i,n) {
        cnt += cb[i];
        if (cnt) {
            cb[i] = 1;
            cnt--;
        }
    }
    rep(i,n) {
        int idx = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
        if (idx < n) cc[idx] += cb[i];
    }
    cnt = 0;
    rep(i,n) {
        cnt += cc[i];
        if (cnt) {
            cc[i] = 1;
            cnt--;
        }
    }
    int ans = 0;
    rep(i,n) ans += cc[i];
    cout << ans << endl;
    return 0;
}

