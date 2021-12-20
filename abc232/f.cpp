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
    ll x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    int n2 = 1<<n;
    vector<ll> dp(n2, LINF);
    dp[0] = 0;
    // a から 1 つずつ選んでならべていく
    // s は a から選んだ要素の集合
    rep(s,n2) {
        int j = __builtin_popcount(s);
        // a の i 番目を j 番目に並べる
        rep(i,n) {
            if (s>>i&1) continue;
            ll cost = abs(a[i] - b[j]) * x;
            // a の i 番目より前にある要素のうちすでに並べられている要素の個数 (転倒数) * y
            cost += __builtin_popcount(s>>i) * y;
            chmin(dp[s|1<<i], dp[s] + cost);
        }
    }
    ll ans = dp[n2-1];
    cout << ans << endl;
    return 0;
}