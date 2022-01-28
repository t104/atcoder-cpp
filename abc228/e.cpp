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

using mint = modint;
const int mod = 998244353;

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    if (m % mod == 0) {
        cout << 0 << endl;
        return 0;
    }
    mint::set_mod(mod-1);
    int r = mint(k).pow(n).val();
    mint::set_mod(mod);
    int ans = mint(m).pow(r).val();
    cout << ans << endl;
    return 0;
}

