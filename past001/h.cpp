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
    vector<vector<ll>> c(2, vector<ll>(n/2 + 1));
    rep(i,n) {
        cin >> c[i%2][i/2];
    }
    int q;
    cin >> q;
    ll ans = 0;
    ll mi[2] = {LINF, LINF};
    ll d[2] = {0, 0};
    rep(i,n) {
        chmin(mi[i%2], c[i%2][i/2]);
    }
    rep(i,q) {
        int p;
        cin >> p;
        if (p == 1) {
            int x;
            ll a;
            cin >> x >> a;
            --x;
            if (a <= c[x%2][x/2] - d[x%2]) {
                c[x%2][x/2] -= a;
                ans += a;
                chmin(mi[x%2], c[x%2][x/2]);
            }
        }
        if (p == 2) {
            ll a;
            cin >> a;
            if (a <= mi[0] - d[0]) {
                ans += a * (n/2 + n%2);
                d[0] += a;
            }
        }
        if (p == 3) {
            ll a;
            cin >> a;
            if (a <= min(mi[0] - d[0], mi[1] - d[1])) {
                ans += a * n;
                d[0] += a;
                d[1] += a;
            }
        }
    }
    cout << ans << endl;
    return 0;
}