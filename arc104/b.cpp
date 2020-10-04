#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

const int max_n = 5005;

int op (int x, int y) {
    return x + y;
}

int e () {
    return 0;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    segtree<int, op, e> a(max_n);
    segtree<int, op, e> t(max_n);
    segtree<int, op, e> g(max_n);
    segtree<int, op, e> c(max_n);

    rep(i,n) {
        if (s.at(i) == 'A') a.set(i, 1);
        if (s.at(i) == 'T') t.set(i, 1);
        if (s.at(i) == 'C') c.set(i, 1);
        if (s.at(i) == 'G') g.set(i, 1);
    }
    int ans = 0;
    rep(i,n) {
        for (int j = 2; i+j <= n; j+=2) {
            int ca = a.prod(i, i+j);
            int ct = t.prod(i, i+j);
            int cg = g.prod(i, i+j);
            int cc = c.prod(i, i+j);
            if (ca == ct && cg == cc) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}