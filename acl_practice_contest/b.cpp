#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fen(n);
    rep(i,n) {
        int a;
        cin >> a;
        fen.add(i, a);
    }
    rep(i,q) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) fen.add(b, c);
        if (a == 1) cout << fen.sum(b, c) << endl;
    }
    return 0;
}