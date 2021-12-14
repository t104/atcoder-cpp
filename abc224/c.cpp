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

const double EPS = 1e-16;

ll cross_product(ll dx1, ll dy1, ll dx2, ll dy2) {
    return dx1 * dy2 - dx2 * dy1;
}

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    int ans = 0;
    rep(i,n) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                ll dx1 = x[j] - x[i];
                ll dy1 = y[j] - y[i];
                ll dx2 = x[k] - x[i];
                ll dy2 = y[k] - y[i];
                ll s = abs(cross_product(dx1, dy1, dx2, dy2));
                if (0 < s) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

