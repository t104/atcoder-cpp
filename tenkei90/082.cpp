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

int main() {
    ll l, r;
    cin >> l >> r;
    ll d = 1;
    mint ans = 0;
    rep(i,19) {
        if (l/10 < d && d <= r) {
            mint a = max(l, d);
            mint b = r/d < 10 ? r : 10*d-1;
            ans += (a+b)*(b-a+1)*mint(i+1)*mint(2).inv();
        }
        d *= 10;
    }
    cout << ans.val() << endl;
    return 0;
}