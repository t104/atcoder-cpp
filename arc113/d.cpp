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
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    if (n == 1 && m == 1) {
        cout << k << endl;
        return 0;
    }
    if (n == 1) {
        ans = ((mint) k).pow(m);
        cout << ans.val() << endl;
        return 0;
    }
    if (m == 1) {
        ans = ((mint) k).pow(n);
        cout << ans.val() << endl;
        return 0;
    }
    for (int i = 1; i <= k; ++i) {
        mint cnt = ((mint) i).pow(n);
        if (1 < i) cnt -= ((mint) i-1).pow(n);
        cnt *= ((mint) k-i+1).pow(m);
        ans += cnt;
    }
    cout << ans.val() << endl;
    return 0;
}