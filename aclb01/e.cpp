#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using mint = modint998244353;
const mint inv9 = mint(1)/9;

struct S {
    mint x, w;
    S(mint x=0, mint w=0): x(x), w(w) {}
};

S op(S a, S b) {
    return S(a.x * b.w + b.x, a.w * b.w);
}

S e() { return S(); }

S mapping(int f, S a) {
    if (f == 0) return a;
    return S((a.w - 1) * inv9 * f, a.w);
}

int composition(int f, int g) {
    if (f == 0) return g;
    return f;
}

int id() { return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    lazy_segtree<S, op, e, int, mapping, composition, id> t(n);
    rep(i,n) t.set(i, S(1, 10));
    rep(qi, q) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        t.apply(l, r, d);
        S ans = t.prod(0, n);
        printf("%d\n", ans.x.val());
    }
    return 0;
}