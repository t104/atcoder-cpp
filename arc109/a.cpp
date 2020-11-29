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

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int ans = 0;
    int d = b - a;
    if (d == 0) {
        ans = x;
    }
    else if (2*x < y) {
        if (0 < d) {
            ans = 2*x*abs(d) + x;
        }
        else {
            ans = 2*x*abs(d) - x;
        }
    }
    else {
        if (0 < d) {
            ans = abs(d) * y + x;
        }
        else {
            ans = (abs(d)-1) * y + x;
        }
    }
    cout << ans << endl;
    return 0;
}