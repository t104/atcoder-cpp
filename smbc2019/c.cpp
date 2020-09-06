#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x;
    cin >> x;
    int ans = 0;
    rep(a, 100) {
        int sa = x;
        sa -= a * 101;
        if (sa < 0) continue;
        rep(b, 50) {
            int sb = sa - b * 102;
            if (sb < 0) break;
            rep(c, 34) {
                int sc = sb - c * 103;
                if (sc < 0) break;
                rep(d, 25) {
                    int sd = sc - d * 104;
                    if (sd < 0) break;
                    rep(e, 20) {
                        int se = sd - e * 105;
                        if (se < 0) break;
                        if (se%100 == 0) ans = 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}