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

const int MX = 1000100;

int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> bit(MX);
    dsu uf(MX);

    rep(i,q) {
        int t, x, y;
        ll v;
        cin >> t >> x >> y >> v;
        --x, --y;
        if (t == 0) {
            uf.merge(x, y);
            if (bit.sum(x, x+1) != 0) continue;
            if (x%2 == 0) {
                bit.add(x, v);
            }
            else {
                bit.add(x, -v);
            }
        }
        else {
            if (uf.same(x, y)) {
                ll k = bit.sum(min(x,y), max(x,y));
                ll ans = 0;
                if (x < y) {
                    y--;
                }
                else {
                    x--;
                }
                if (x%2 == 0 && y%2 == 0) {
                    ans = k - v;
                }
                else if (x%2 == 0 && y%2 == 1) {
                    ans = -k + v;
                }
                else if (x%2 == 1 && y%2 == 0) {
                    ans = k + v;
                }
                else {
                    ans = -k - v;
                }
                // cout << k << ' ' <<  v << ' ' << ans << endl;
                cout << ans << endl;
            }
            else {
                cout << "Ambiguous" << endl;
            }
        }
    }
    return 0;
}