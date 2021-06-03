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
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                for (int l = k+1; l < n; ++l) {
                    for (int m = l+1; m < n; ++m) {
                        ll r = 1;
                        for (auto &x: {i,j,k,l,m}) {
                            r *= a[x];
                            r %= p;
                        }
                        if (r == q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}