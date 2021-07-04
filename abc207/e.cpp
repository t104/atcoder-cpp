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
// dp[i][j]: 最後の区切りがi、次j番目のグループの遷移
mint dp[MAX_N][MAX_N];

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i] + a[i];

    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            mint now;
            for (int k = 0; k < i; ++k) {
                if ((s[i]-s[k])%j == 0) now += dp[k][j];
            }
            dp[i][j+1] = now;
        }
    }

    mint ans = 0;
    for (int j = 1; j <= n+1; ++j) ans += dp[n][j];
    cout << ans.val() << endl;
    return 0;
}