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

map<string,mint> dp[105];
const string all = "ATGC";
const string trp[] = {"AGC", "GAC", "ACG"};

int main() {
    int n;
    cin >> n;
    rep(i,4) rep(j,4) rep(k,4) {
        string s = string({all[i], all[j], all[k]});
        dp[3][s] = 1;
    }

    for (auto s: trp) dp[3][s] = 0;

    for (int i = 3; i < n; ++i) {
        rep(c1, 4) rep(c2, 4) rep(c3, 4) {
            string s = string({all[c1], all[c2], all[c3]});
            rep(c4,4) {
                string t = string({all[c2], all[c3], all[c4]});
                if (all[c1]=='A' && all[c3]=='G' && all[c4]=='C') continue;
                if (all[c1]=='A' && all[c2]=='G' && all[c4]=='C') continue;
                bool ok = true;
                for (auto u: trp) if (t == u) ok = false;
                if (ok) {
                    dp[i+1][t] += dp[i][s];
                }
            }
        }
    }

    mint ans = 0;
    for (auto i: dp[n]) {
        ans += i.second;
    }
    cout << ans.val() << endl;
    
    return 0;
}