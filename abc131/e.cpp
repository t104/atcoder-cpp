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

int n, k;

int test(vector<P> &ans) {
    vector<vector<int>> dp(n, vector<int>(n, INF));
    rep(i,n) dp[i][i] = 0;
    for (auto [u,v]: ans) {
        --u, --v;
        dp[u][v] = 1;
        dp[v][u] = 1;
    }
    rep(k,n) rep(i,n) rep(j,n) {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }
    int res = 0;
    rep(i,n) for (int j = i+1; j < n; ++j) {
        if (dp[i][j] == 2) res++;
    }
    return res;
}

void ng() {
    cout << -1 << endl;
    exit(0);
}

vector<P> solve() {
    int mx = (n-1)*(n-2)/2;
    if (mx < k) {
        ng();
    }

    int m = n-1+mx-k;

    vector<P> ans;
    for (int i = 2; i <= n; ++i) {
        ans.emplace_back(1, i);
        m--;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (m == 0) return ans;
            ans.emplace_back(i,j);
            m--;
        }
    }
    return ans;
}

int main() {
    cin >> n >> k;

    vector<P> ans = solve();

    cout << ans.size() << endl;
    for (auto [u,v]: ans) {
        cout << u << ' ' << v << endl;
    }

    // cout << test(ans) << endl;

    return 0;
}