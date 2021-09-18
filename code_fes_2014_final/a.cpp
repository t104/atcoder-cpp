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

int op (int x, int y) {
    return max(x, y);
}

int e () {
    return 0;
}

using seg = segtree<int, op, e>;

int dp[3010][2];

int main() {
    int n;
    cin >> n;
    vector<P> r(n);
    rep(i,n) {
        int ri;
        cin >> ri;
        r[i] = make_pair(ri, i);
    }
    vector<int> order(n);
    sort(r.begin(), r.end());
    int idx = 1;
    rep(i,n) {
        if (0 < i && r[i-1].first != r[i].first) idx++;
        order[r[i].second] = idx;
    }
    rep(i,n) {
        int increasing = 0, decreasing = 0;
        rep(j,3010) {
            if (j < order[i]) chmax(increasing, dp[j][0]);
            if (order[i] < j) chmax(decreasing, dp[j][1]);
        }
        chmax(dp[order[i]][1], increasing + 1);
        chmax(dp[order[i]][0], decreasing + 1);
    }
    int ans = 0;
    rep(i, 3010) {
        chmax(ans, dp[i][0]);
        chmax(ans, dp[i][1]);
    }
    if (ans < 3) ans = 0;
    cout << ans << endl;
    return 0;
}

