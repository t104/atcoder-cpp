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
using mint = modint998244353;

const int MX = 10010;
mint dp[MX][1<<10][2];
mint ds[MX][1<<10][2];

int main() {
    string N;
    cin >> N;
    int cs = 0;
    int n = N.size();
    {
        int m;
        cin >> m;
        rep(i,m) {
            int c;
            cin >> c;
            cs |= 1 << c;
        }
    }
    rep(i,n) {
        int ni = i + 1;
        int d = N[i] - '0';
        rep(s, 1<<10) rep(j,2) {
            mint num = dp[i][s][j];
            mint sum = ds[i][s][j];
            rep(x, 10) {
                int ns = s, nj = j;
                if (j == 0) {
                    if (d < x) continue;
                    if (x < d) nj = 1;
                }
                ns |= 1 << x;
                dp[ni][ns][nj] += num;
                ds[ni][ns][nj] += sum * 10 + num * x;
                if (s == 0 && (i == 0 ? 0 : 1) == j && x != 0) {
                    dp[ni][ns][nj] += 1;
                    ds[ni][ns][nj] += x;
                }
            }
        }
    }
    mint ans;
    rep(s, 1<<10) if ((s & cs) == cs) rep(j,2) {
        ans += ds[n][s][j];
    }
    cout << ans.val() << endl;
    return 0;
}