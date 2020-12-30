// ref: https://atcoder.jp/contests/joi2015ho/submissions/12495303
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int MX = 4010;

int n;
vector<vector<ll>> dp;
vector<ll> a;

ll dfs(int l, int r, bool joisTurn) {
    l = (l+n)%n;
    r = (r+n)%n;
    // DPテーブルに答えがあれば返す
    if (0 <= dp[l][r]) {
        return dp[l][r];
    }
    if (l == r) {
        if (joisTurn) {
            return dp[l][r] = a[l];
        }
        return dp[l][r] = 0;
    }
    // JOIのターンのとき、左隣のピース(a[l])を取る場合と右隣のピース(a[r])を取る場合の大きいほうが答え
    if (joisTurn) {
        return dp[l][r] = max(a[l] + dfs(l+1, r, false),  dfs(l, r-1, false) + a[r]);
    }
    // IOIのターンのとき、IOIは左隣のピースと右隣のピースの大きい方を取る
    if (a[l] < a[r]) {
        return dp[l][r] = dfs(l, r-1, true);
    }
    return dp[l][r] = dfs(l+1, r, true);
}

int main() {
    cin >> n;
    a.resize(n);
    dp.assign(n, vector<ll>(n, -1));
    rep(i,n) {
        cin >> a[i];
    }

    ll ans = 0;
    rep(i,n) {
        chmax(ans, dfs(i, i+n-1, true));
    }

    auto print_dp = [&](){
        rep(i,n) {
            rep(j,n) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
    };
    
    // print_dp();
    cout << ans << endl;
    return 0;
}