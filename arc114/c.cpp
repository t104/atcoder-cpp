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

using mint = modint998244353;

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
const int MAX_N = 1000005;
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} c(MAX_N);

mint dp[5005][5005];

int main() {
    int n, m;
    cin >> n >> m;
    mint ans = n * mint(m).pow(n);
    vector<mint> powM(n+1);
    powM[0] = 1;
    rep(i,n) powM[i+1] = powM[i] * m;
    for (int x = 1; x <= m; ++x) {
      vector<mint> tmp(n+1);
      tmp[0] = 1;
      rep(i,n) tmp[i+1] = tmp[i] * (m-x);
      for (int w = 2; w <= n; ++w) {
        ans -= tmp[w-2] * mint(n-w+1) * powM[n-w];
      }
    }
    cout << ans.val() << endl;
    return 0;
}