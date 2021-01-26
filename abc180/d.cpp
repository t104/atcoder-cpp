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

int main() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll cnt = 0;
    while (x < y/a + 1 && x * a < y && x * a < x + b) {
        x *= a;
        cnt++;
    }
    cnt += (y-x-1) / b;

    cout << cnt << endl;
    return 0;
}