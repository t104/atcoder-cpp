#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL << 60)
#define rep(i, n) for(int i = 0; i < (n); ++i)
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2, typename T3>
inline bool in(T1 val, T2 l, T3 r) {
    return l <= val && val < r;
}
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const double eps = 1e-6;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n), c(n), d(n);
    int g1x = 0, g1y = 0, g2x = 0, g2y = 0;
    rep(i, n) {
        cin >> a[i] >> b[i];
        g1x += a[i];
        g1y += b[i];
        a[i] *= n;
        b[i] *= n;
    }
    rep(i, n) {
        cin >> c[i] >> d[i];
        g2x += c[i];
        g2y += d[i];
        c[i] *= n;
        d[i] *= n;
    }
    rep(i,n) {
        a[i] -= g1x;
        b[i] -= g1y;
        c[i] -= g2x;
        d[i] -= g2y;
    }
    rep(i,n) {
        if (a[i] != 0 || b[i] != 0) {
            swap(a[i], a[0]);
            swap(b[i], b[0]);
        }
    }

    rep(i,n) {
        double angle = atan2(d[i], c[i]) - atan2(b[0], a[0]);
        bool flag = true;
        rep(j,n) {
            double ai = a[j]*cos(angle) - b[j]*sin(angle);
            double bi = a[j]*sin(angle) + b[j]*cos(angle);
            
            bool flag2 = false;
            rep(k,n) {
                if (abs(ai-c[k]) <= eps && abs(bi-d[k]) <= eps) {
                    flag2 = true;
                }
            }
            flag &= flag2;
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

        return 0;
}