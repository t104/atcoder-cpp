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

using S = int;
using F = int;

const F ID = INF;

S op(S a, S b) {
    return max(a,b);
}

S e() {
    return -INF;
}

S mapping(F f, S x) {
    return (f == ID ? x : f);
}

F composition(F f, S g) {
    return (f == ID ? g : f);
}

F id() {
    return ID;
}

int main() {
    int w, n;
    cin >> w >> n;
    vector<S> v(w);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    rep(i,n) {
        int l, r;
        cin >> l >> r;
        int h = seg.prod(l-1, r) + 1;
        seg.apply(l-1, r, h);
        cout << h << endl;
    }
    return 0;
}