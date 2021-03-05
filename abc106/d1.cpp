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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> sum(n+1, vector<int>(n+1));
    rep(i,m) {
        int l, r;
        cin >> l >> r;
        sum[l][r]++;
    }
    rep(i,n) {
        rep(j,n) {
            sum[i+1][j+1] += sum[i+1][j] + sum[i][j+1] - sum[i][j];
        }
    }
    rep(i,q) {
        int p, q;
        cin >> p >> q;
        cout << sum[q][q] - sum[p-1][q] - sum[q][p-1] + sum[p-1][p-1] << endl;
    }
    return 0;
}