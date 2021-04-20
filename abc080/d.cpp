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

const int MX = 100010;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> sum(30, vector<int>(MX));
    rep(i,N) {
        int s, t, c;
        cin >> s >> t >> c;
        --c;
        sum[c][s]++;
        sum[c][t+1]--;
    }
    int ans = 0;
    rep(i,30) {
        rep(j,MX-1) {
            sum[i][j+1] += sum[i][j];
        }
    }
    rep(i,MX-1) {
        int sub = 0;
        rep(j,30) {
            if (sum[j][i]) sub++;
        }
        chmax(ans, sub);
    }
    cout << ans << endl;
    return 0;
}