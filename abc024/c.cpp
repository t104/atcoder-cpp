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
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> L(d), R(d);
    rep(i,d) cin >> L[i] >> R[i];
    vector<int> ans(k);
    rep(i,k) {
        int l, r, t;
        cin >> l >> t;
        r = l;
        rep(j, d) {
            if ((L[j] <= l && l <= R[j]) || (L[j] <= r && r <= R[j])) {
                chmin(l, L[j]);
                chmax(r, R[j]);
            }
            if (l <= t && t <= r) {
                ans[i] = j+1;
                break;
            }
        }
    }
    rep(i,k) cout << ans[i] << endl;
    return 0;
}

