#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    gy *= -1;
    double ans =(double) sx - (double) ((ll) sy * (gx-sx)) / (ll) (gy-sy);
    cout << std::fixed << std::setprecision(15);
    cout << ans << endl;
    return 0;
}