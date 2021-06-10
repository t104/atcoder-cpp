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

ll op (ll x, ll y) {
    return max(x,y);
}

ll e () {
    return 0;
}

const int MX = 300010;
vector<segtree<ll, op, e>> dp(2, segtree<ll, op, e>(MX));
int n;

// void print_dp() {
//     rep(i,2)  {
//         rep(j,n+1) {
//             cout << dp[j][i] << ' ';
//         }
//         cout << endl;
//     }
// }

int main() {
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n) {
        ll tmp = dp[0].prod(0, a[i]) + 1;
        if (dp[0].get(a[i]) < tmp) {
            dp[0].set(a[i], tmp);
        }
        tmp = dp[1].prod(a[i]+1, MX) + 1;
        if (dp[1].get(a[i]) < tmp) {
            dp[1].set(a[i], tmp);
        }
        tmp = dp[0].prod(a[i] + 1, MX) + 1;
        if (dp[1].get(a[i]) < tmp) {
            dp[1].set(a[i], tmp);
        }
    }

    ll ans = max(dp[0].all_prod(), dp[1].all_prod());
    cout << ans << endl;
    return 0;
}