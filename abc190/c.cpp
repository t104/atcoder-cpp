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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(m,vector<int>(2));
    rep(i,m) rep(j,2) {
        cin >> c[i][j];
        c[i][j]--;
    }
    int k;
    cin >> k;
    vector<vector<int>> b(k,vector<int>(2));
    rep(i,k) rep(j,2) {
        cin >> b[i][j];
        b[i][j]--;
    }

    int ans = 0;
    rep(i,1<<k) {
        vector<int> d(n);
        rep(j,k) {
            d[b[j][(i>>j)&1]]++;
        }
        int cnt = 0;
        rep(j,m) {
            if (0 < d[c[j][0]] && 0 < d[c[j][1]])
                cnt++;
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}