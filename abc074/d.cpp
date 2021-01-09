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
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i,n) rep(j,n) cin >> a[i][j];

    bool possible = true;
    vector<vector<bool>> remove(n, vector<bool>(n, false));
    rep(i,n) {
        rep(j,n) {
            rep(k,n) {
                if (k ==i || k == j) continue;
                if (a[i][j] == a[i][k] + a[k][j])
                    remove[i][j] = true;
                if (a[i][k] + a[k][j] < a[i][j])
                    possible = false;
            }
        }
    }

    ll ans = 0;
    rep(i,n) {
        rep(j,n) {
            if (!remove[i][j]) {
                ans += a[i][j];
            }
        }
    }
    ans /= 2;
    if (possible) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}