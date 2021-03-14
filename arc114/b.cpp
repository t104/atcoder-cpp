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
    int n;
    cin >> n;
    vector<int> f(n);
    rep(i,n) {
        cin >> f[i];
        f[i]--;
    }
    dsu d(n);
    rep(i,n) {
        d.merge(i, f[i]);
    }
    mint ans = mint(2).pow(d.groups().size());
    ans--;
    cout << ans.val() << endl;
    return 0;
}