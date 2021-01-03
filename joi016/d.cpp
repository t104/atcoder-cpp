#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 100005;
const int max_m = 20;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> sum(n, vector<int>(m));
    sum[0][a[0]]++;
    for (int i = 1; i < n; ++i) {
        rep(j,m) sum[i][j] += sum[i-1][j];
        sum[i][a[i]]++;
    }

    vector<int> count(m);
    rep(i,n) {
        count[a[i]]++;
    }
    
    vector<int> dp((1<<m), INF);
    dp[0] = 0;
    for (int flg = 0; flg < (1<<m); ++flg) {
        int l = 0;
        for (int mi = 0; 0 < (flg>>mi); mi++) {
            if ((flg>>mi)&1)
                l += count[mi];
        }
        for (int mi = 0; mi < m; ++mi) {
            if ((flg>>mi)&1) continue;
            int r = l + count[mi];
            int cnt = dp[flg];
            for (int mj = 0; mj < m; ++mj) {
                if (mj == mi) continue;
                cnt += sum[r-1][mj];
                if (0 < l) cnt -= sum[l-1][mj];
            }
            chmin(dp[flg|(1<<mi)], cnt);
        }
    }

    cout << dp[(1<<m)-1] << endl;
    
    return 0;
}