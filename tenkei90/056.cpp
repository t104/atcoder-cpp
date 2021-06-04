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
using P = pair<int,string>;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<P> dp(100010, make_pair(-1, ""));
    dp[0].first = 0;
    rep(i,n) {
        for (int j = 100000; 0 < j; --j) {
            if (0 <= j - a[i] && dp[j-a[i]].first == i) {
                dp[j].second = dp[j-a[i]].second;
                dp[j].second.push_back('A');
                dp[j].first = dp[j].second.size();
            }
            if (0 <= j - b[i] && dp[j-b[i]].first == i) {
                dp[j].second = dp[j-b[i]].second;
                dp[j].second.push_back('B');
                dp[j].first = dp[j].second.size();
            }
        }
    }
    if (dp[s].first != n) cout << "Impossible" << endl;
    else cout << dp[s].second << endl;
    return 0;
}