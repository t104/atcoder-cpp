#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int op (int x, int y) {
    return x ^ y;
}

int e () {
    return 0;
}

int mapping(int f, int a) {
    return f^a;
}

int composition(int f, int g) {
    return f^g;
}

int id() {return 0;}

int main() {
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> seg(n);
    rep(i,n) {
        int ai;
        cin >> ai;
        seg.set(i, ai);
    }

    rep(qi, q) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1) {
            int ax = seg.get(x);
            seg.set(x, ax^y);
        }
        if (t == 2) {
            cout << seg.prod(x, y) << endl;
        }
    }
    return 0;
}