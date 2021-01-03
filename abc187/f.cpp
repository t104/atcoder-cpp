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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<int> e(n);

    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        e[a[i]] |= 1 << b[i];
        e[b[i]] |= 1 << a[i];
    }

    vector<int> dp(1<<n, INF);
    dp[0] = 0;
    for (int i = 1; i < (1<<n); ++i) {
        rep(j,n) {
            if ((i & (1<<j)) == 0) continue;
            int target = i - (1<<j);
            if (dp[target] <= 1 && (e[j] & target) == target) {
                dp[i] = 1;
            }
            break;
        }
    }

    for (int i = 0; i < (1<<n); ++i) {
        for (int j = i; 0 < j; j = (j-1) & i) {
            int k = i-j;
            chmin(dp[i], dp[j] + dp[k]);
        }
    }

    cout << dp[(1<<n) - 1] << endl;
    
    return 0;
}