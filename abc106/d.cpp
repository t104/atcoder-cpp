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

const int MX = 505;
int sum[MX][MX];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    rep(i,m) {
        int li, ri;
        cin >> li >> ri;
        sum[li][ri]++;
    }

    rep(i,MX-1) {
        rep(j,MX-1) {
            sum[i][j+1] += sum[i][j];
        }
    }

    rep(i,MX-1) {
        rep(j,MX-1) {
            sum[i+1][j] += sum[i][j];
        }
    }

    rep(qi, q) {
        int x, y;
        cin >> x >> y;
        int ans = sum[y][y] - sum[x-1][y] - sum[y][x-1] + sum[x-1][x-1];
        cout << ans << endl;
    }

    return 0;
}