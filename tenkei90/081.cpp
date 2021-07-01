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

const int MX = 5010;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> table(MX, vector<int>(MX));
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        table[a][b]++;
    }

    rep(i,MX) rep(j,MX-1) table[i][j+1] += table[i][j];
    rep(j, MX) rep(i, MX-1) table[i+1][j] += table[i][j];

    int ans = 0;
    for (int i = 1; i < MX-k-1; ++i) {
        for (int j = 1; j < MX-k-1; ++j) {
            int cnt = table[i+k][j+k] - table[i-1][j+k] - table[i+k][j-1] + table[i-1][j-1];
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;
    
    return 0;
}