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

vector<vector<int>> dp(10000);
vector<int> a;
vector<vector<int>> x;
int n, q;

void dfs(int v, int sum, vector<bool> cand, vector<int> hist) {
    cand[v] = false;
    for (auto xi: x[v]) cand[xi] = false;
    hist.push_back(v);
    sum += a[v];

    if (dp[sum].size()) {
        cout << dp[sum].size() << endl;
        for (auto i: dp[sum]) cout << i+1 << ' ';
        cout << endl;
        cout << hist.size() << endl;
        for (auto i : hist) cout << i+1 << ' ';
        cout << endl;
        exit(0);
    }

    dp[sum] = hist;

    for (int i = v+1; i < n; ++i) {
        if (cand[i]) {
            dfs(i, sum, cand, hist);
        }
    }
}


int main() {
    cin >> n >> q;
    a.resize(n);
    rep(i,n) cin >> a[i];
    x.resize(n);
    rep(i,q) {
        int xi, yi;
        cin >> xi >> yi;
        xi--, yi--;
        x[xi].push_back(yi);
        x[yi].push_back(xi);
    }
    rep(i,n) {
        dfs(i, 0, vector<bool>(n, true), {});
    }
    return 0;
}