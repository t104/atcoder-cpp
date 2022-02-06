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

int main() {
    ll n;
    cin >> n;
    mint ans = 0;
    mint p = 0;
    ll x = 1;
    for (; x * 10LL <= n; x *= 10) {
        p = (mint(1) + mint(x*9)) * mint(x*9) * mint(2).inv();
        ans += p;
    }
    ans += (mint(1) + mint(n-x+1)) * mint(n-x+1) * mint(2).inv();
    cout << ans.val() << endl;
    return 0;
}

