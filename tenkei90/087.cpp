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

vector<vector<int>> a;
int N, P, K;

int snuke_count(int x) {
    int res = 0;
    vector<vector<int>> dp = a;
    rep(i,N) rep(j,N) {
        if (dp[i][j] == -1) dp[i][j] = x;
    }
    rep(k,N) rep(i,N) rep(j,N) {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }
    rep(i,N) {
        for (int j = i+1; j < N; ++j) {
            if (dp[i][j] <= P) res++;
        }
    }
    return res;
}

int main() {
    cin >> N >> P >> K;
    a.assign(N, vector<int>(N));
    rep(i,N) rep(j,N) cin >> a[i][j];
    if (snuke_count(INF) == K) {
        cout << "Infinity" << endl;
        return 0;
    }
    if (snuke_count(1) < K) {
        cout << 0 << endl;
        return 0;
    }
    int R, L;
    {
        int l = 0, r = INF;
        while (l+1 < r) {
            int mid = (l+r)/2;
            bool ok = K <= snuke_count(mid);
            if (ok) l = mid;
            else r = mid;
        }
        R = l;
    }
    {
        int l = 0, r = INF;
        while (l+1 < r) {
            int mid = (l+r)/2;
            bool ok = K < snuke_count(mid);
            if (ok) l = mid;
            else r = mid;
        }
        L = l;
    }
    cout << R-L << endl;
    return 0;
}