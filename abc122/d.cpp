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

const vector<string> base = {"A", "C", "G", "T"};
vector<map<string,mint>> dp(105);

bool agc2(string s, string t) {
    if (s == "AG" && t == "C") return true;
    if (s == "AC" && t == "G") return true;
    if (s == "GA" && t == "C") return true;
    return false;
}

bool agc3(string s, string t) {
    if (agc2(s.substr(1,2), t)) return true;
    if (s[0] == 'A' && s[2] == 'G' && t == "C") return true;
    if (s.substr(0,2) == "AG" && t == "C") return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    dp[0][""] = 1;
    rep(i,n) {
        for (auto p: dp[i]) {
            if (p.first.size() <= 1) {
                for (auto &b: base) {
                    dp[i+1][p.first+b] += p.second;
                }
            }
            else if (p.first.size() == 2) {
                for (auto &b: base) {
                    if (agc2(p.first, b)) continue;
                    dp[i+1][p.first+b] += p.second;
                }
            }
            else {
                for (auto &b: base) {
                    string s = p.first.substr(1,2);
                    if (agc3(p.first, b)) continue;
                    dp[i+1][s+b] += p.second;
                }
            }
        }
    }
    mint ans = 0;
    for (auto p: dp[n]) {
        ans += p.second;
    }
    cout << ans.val() << endl;
    return 0;
}