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

const int MX = 130;
ll a[MX][MX];

int main() {
    int h, w;
    ll k, v;
    cin >> h >> w >> k >> v;
    rep(i,h) {
        rep(j,w) {
            cin >> a[i+1][j+1];
        }
    }

    rep(i,MX-1) {
        rep(j,MX-1) {
            a[i][j+1] += a[i][j];
        }
    }

    rep(i,MX-1) {
        rep(j,MX-1) {
            a[j+1][i] += a[j][i];
        }
    }

    ll ans = 0;
    for (int hi = 1; hi <= h; hi++) {
        for (int wi = 1; wi <= w; wi++) {
            for (int hj = hi; hj <= h; ++hj) {
                for (int wj = wi; wj <= w; ++wj) {
                    ll s = (hj-hi+1) * (wj-wi+1);
                    ll p = k * s;
                    if (v < p) break;
                    p += a[hj][wj] - a[hi-1][wj] - a[hj][wi-1] + a[hi-1][wi-1];
                    if (p <= v) {
                        chmax(ans, s);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}