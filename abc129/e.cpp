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

mint dp[100010][2];
const int mod = 1000000007;

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
const int MAX_N = 1000005;
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    mint ans = 0;
    int cnt = 0;
    rep(i,n) {
        if (s[i] == '1') {
            ans += mint(3).pow(n-1-i) * mint(2).pow(cnt);
            cnt++;
        }
    }
    ans += mint(2).pow(cnt);
    cout << ans.val() << endl;
    return 0;
}