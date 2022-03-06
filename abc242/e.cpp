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
using mint = modint998244353;

mint solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> t(n);
    rep(i,n) t[i] = s[i] - 'A';
    mint ans = 0;
    int m = (n+1)/2;
    rep(i,m) {
        ans += t[i] * mint(26).pow(m-1-i);
    }
    string s2 = s.substr(0, m);
    reverse(s2.begin(), s2.end());
    s2 = s.substr(0, n-m) + s2;
    // cerr << s2 << endl;
    if (s2 <= s) ans += 1;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve().val() << endl;
    }
    return 0;
}

