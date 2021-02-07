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
using P = pair<int,int>;

const ll prec = 10000LL;
double X, Y, R;
ll XX, YY, RR;

bool inside(int x, int y) {
    ll lx = (ll) x * prec;
    ll ly = (ll) y * prec;
    return (lx-XX)*(lx-XX) + (ly-YY)*(ly-YY) <= RR*RR;
}

int calc_left(double x) {
    int top = floor(Y);
    int bottom = top - floor(R) - 10;
    if (!inside(x, top)) return 0;
    while (1 < top - bottom) {
        int mid = (top + bottom) / 2;
        if (inside(x, mid)) top = mid;
        else bottom = mid;
    }
    return floor(Y) - bottom;
}

int calc_right(double x) {
    int bottom = floor(Y) + 1;
    int top = bottom + floor(R) + 10;
    if (!inside(x, bottom)) return 0;
    while (1 < top - bottom) {
        int mid = (top + bottom) / 2;
        if (inside(x, mid)) bottom = mid;
        else top = mid;
    }
    return top - (floor(Y) + 1);
}

int main() {
    cin >> X >> Y >> R;
    XX = round(X * prec);
    YY = round(Y * prec);
    RR = round(R * prec);
    ll ans = 0;
    for (int x = X-R-10; x < X+R+10; ++x) {
        int l = calc_left(x);
        int r = calc_right(x);
        // printf("%d %d %d\n", x, l, r);
        ans += (ll) l + r;
    }
    cout << ans << endl;
    return 0;
}