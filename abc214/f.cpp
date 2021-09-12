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

using mint = modint1000000007;

const int MX = 200010;
mint dp[MX];
int n;

int main() {
    string s;
    cin >> s;
    n = s.size();
    dp[0] = 1;
    mint ans = 0;
    rep(i,n) {
        for (int j = i; 0 <= j; --j) {
            dp[i+2] += dp[j];
            if (j && s[j-1] == s[i]) break;
        }
        ans += dp[i+2];
    }
    cout << ans.val() << endl;
    return 0;
}

