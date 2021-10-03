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

const int MX = 300010;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    rep(i,n) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    rep(i,n) {
        c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    fenwick_tree<mint> tree(MX);
    mint ans = 0;
    rep(i,n) {
        if (0 < i) ans += mint(2).pow(i-1) * tree.sum(0, c[i]+1);
        tree.add(c[i], mint(2).pow(i).inv());
    }
    cout << ans.val() << endl;
    return 0;
}

