#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1<<24;
const int SEG_LEN = 1<<19;


struct segtree {
    vector<int> seg;

    segtree () {
        seg.resize(SEG_LEN * 2);
    }

    void set (int pos, int val) {
        pos += SEG_LEN;
        seg.at(pos) = val;
        while (0 < (pos /= 2)) {
            seg.at(pos) = min(seg.at(pos * 2), seg.at(pos*2 + 1));
        }
    }

    void update (int pos, int val) {
        set(pos, min(val, seg.at(SEG_LEN + pos)));
    }

    int getMin(int ql, int qr, int sl = 0, int sr = SEG_LEN, int pos = 1) {
        if (sr <= ql || qr <= sl) return INF;
        if (ql <= sl && sr <= qr) return seg.at(pos);
        int sm = (sl + sr) / 2;
        int lmin = getMin(ql, qr, sl, sm, pos * 2);
        int rmin = getMin(ql, qr, sm, sr, pos * 2 + 1);
        return min(lmin, rmin);
    }

};

int main() {
    int n, q;
    cin >> n >> q;

    ll ans = ll (n-2) * (n-2);
    segtree sh, sw;
    rep(i, n) {
        sh.set(i, n);
        sw.set(i, n);
    }
    
    rep(i, q) {
        int q, x;
        cin >> q >> x;

        if (q == 1) {
            int r = sw.getMin(x, n);
            ans -= r - 2;
            // printf("x: %d r: %d\n", x, r);
            sh.update(r-1, x);
        }
        else {
            int r = sh.getMin(x, n);
            ans -= r - 2;
            // printf("x: %d r: %d\n", x, r);
            sw.update(r-1, x);
        }
    }

    cout << ans << endl;
    return 0;
}