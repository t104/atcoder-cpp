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

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    vector<int> d(10);
    ll p = 1;
    int q = 0;
    for (int i = 1; i < 10; ++i) {
        p *= a;
        p %= 10;
        if (d[p]) {
            q = i-1;
            break;
        }
        d[p] = i;
    }

    mint::set_mod(q);
    mint r = ((mint) b).pow(c);
    int ans = 0;
    int s = r.val();
    if (s == 0) s = q;
    rep(i,10) {
        if (d[i] == s) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}