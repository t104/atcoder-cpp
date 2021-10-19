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

int op (int x, int y) {
    return min(x, y);
}

int e () {
    return INF;
}

int mapping(int f, int x) {
    return f + x;
}

int composition(int f, int g) {
    return f + g;
}

int id() {
    return 0;
}

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> p(n+1), sum(n+1);
    rep(i,n) {
        p[i+1] = s[i] == '(' ? 1 : -1;
        sum[i+1] = p[i+1];
        sum[i+1] += sum[i];
    }
    lazy_segtree<int, op, e, int, mapping, composition, id> tree(sum);
    rep(i,q) {
        int command, l, r;
        cin >> command >> l >> r;
        if (command == 1) {
            if (p[l] == 1 && p[r] == -1) {
                tree.apply(l, r, -2);
            } else if (p[l] == -1 && p[r] == 1) {
                tree.apply(l, r, 2);
            }
            swap(p[l], p[r]);
        } else {
            int ls = tree.get(l - 1), rs = tree.get(r);
            int mi = tree.prod(l, r + 1);
            if (ls == rs && ls == mi) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

