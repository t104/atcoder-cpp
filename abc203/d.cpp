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
    int n, k;
    cin >> n >> k;
    int median = k*k/2 + 1;
    vector a(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> a[i][j];

    int l = -1, r = INF;
    while (l+1 < r) {
        int m = (l+r)/2;
        // 中央値が m 以下
        // m より大きい値が k*k/2 + 1 より少ない
        bool ok = false;
        vector sum(n+1, vector<int>(n+1));
        rep(i,n) rep(j,n) {
            sum[i+1][j+1] = m < a[i][j] ? 1: 0;
        }
        rep(i,n+1) rep(j,n) sum[i][j+1] += sum[i][j];
        rep(i,n) rep(j,n+1) sum[i+1][j] += sum[i][j];
        rep(i,n-k+1) rep(j,n-k+1) {
            int now = sum[i+k][j+k];
            now -= sum[i][j+k];
            now -= sum[i+k][j];
            now += sum[i][j];
            if (now < median) ok = true;
        }

        if (ok) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}