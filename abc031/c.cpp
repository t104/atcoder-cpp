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
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = -INF;
    rep(i,n) {
        int amx = -INF, tmp = 0;
        rep(j,n) {
            if (i == j) continue;
            int l = min(i,j);
            int r = max(i,j);
            int aoki = 0, taka = 0;
            for (int k = l; k <= r; ++k) {
                if (k%2 == l%2) taka += a[k];
                else aoki += a[k];
            }
            if (chmax(amx, aoki)) tmp = taka;
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}