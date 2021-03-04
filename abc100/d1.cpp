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
    vector<vector<ll>> cakes(n, vector<ll>(3));
    rep(i,n) rep(j,3) cin >> cakes[i][j];

    ll ans = 0;
    rep(i,8) {
        sort(cakes.begin(), cakes.end(), [&](auto c, auto d){
            ll sc = 0, sd = 0;
            rep(j,3) {
                if ((i>>j)&1) {
                    sc += c[j];
                    sd += d[j];
                }
                else {
                    sc -= c[j];
                    sd -= d[j];
                }
            }
            return sd < sc;
        });
        vector<ll> sum(3);
        rep(j,m) {
            rep(k,3) {
                sum[k] += cakes[j][k];
            }
        }
        chmax(ans, abs(sum[0]) + abs(sum[1]) + abs(sum[2]));
    }

    cout << ans << endl;
    return 0;
}