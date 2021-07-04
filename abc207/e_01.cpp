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

using mint = modint1000000007;
const int MAX_N = 3005;
mint dp[MAX_N][MAX_N];
// ds[j][k]: mod j で k
mint ds[MAX_N][MAX_N];
int n;

void print_ds() {
    rep(i,n+1) {
        rep(j,n+1) {
            cout << ds[i][j].val() << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i] + a[i];

    dp[0][1] = 1;
    // mod 1 であまりが 0 が 1
    ds[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; 1 <= j; --j) {
            mint now = ds[j][s[i]%j];
            dp[i][j+1] = now;
            ds[j+1][s[i]%(j+1)] += now;
        }
    }

    mint ans = 0;
    for (int j = 1; j <= n+1; ++j) ans += dp[n][j];
    cout << ans.val() << endl;
    print_ds();
    return 0;
}