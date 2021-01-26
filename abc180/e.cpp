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
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i,n) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<int>> dp(1<<n, vector<int>(n, INF));
    dp[0][0] = 0;
    rep(i,1<<n) {
        rep(vi,n) {
            rep(vj,n) {
                if (vi == vj) continue;
                chmin(
                    dp[i | (1<<vj)][vj],
                    dp[i][vi] + abs(x[vj]-x[vi]) + abs(y[vj]-y[vi]) + max(0, z[vj]-z[vi])
                );
            }
        }
    }
    cout << dp[(1<<n)-1][0] << endl;
    return 0;
}