#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
const int MAX_N = 1000005;
const int mod = 1000000007;
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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        mint ans = c(n-k+1, i) * c(k-1, i-1);
        cout << ans.val() << endl;
    }
    return 0;
}