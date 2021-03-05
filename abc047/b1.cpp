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

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int mih = 0, miw = 0, mxh = h, mxw = w;
    rep(i,n) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) chmax(miw, x);
        if (a == 2) chmin(mxw, x);
        if (a == 3) chmax(mih, y);
        if (a == 4) chmin(mxh, y);
    }
    cout << max(0, mxh-mih) * max(0, mxw-miw) << endl;
    return 0;
}