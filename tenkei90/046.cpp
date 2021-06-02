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
    vector a(3, vector<int>(46));
    rep(i,3) rep(j,n) {
        int x;
        cin >> x;
        x %= 46;
        a[i][x]++;
    }

    ll ans = 0;
    rep(i,46) rep(j,46) {
        ans += (ll) a[0][i] * a[1][j] * a[2][(92-i-j)%46];
    }
    cout << ans << endl;
    return 0;
}