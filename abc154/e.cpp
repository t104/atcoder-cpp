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

ll comb(int n, int r) {
    if (n < r) return 0LL;
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));
    rep(i, v.size()) {
        v.at(i).at(0) = 1;
        v.at(i).at(i) = 1;
    }
    for (int j = 1; j < v.size(); ++j) {
        for (int k = 1; k < j; ++k) {
            v.at(j).at(k) = v.at(j-1).at(k-1) + v.at(j-1).at(k);
        }
    }
    return v[n][r];
}

ll p(ll a, int x) {
    ll res = 1;
    rep(i,x) res *= a;
    return res;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    ll ans = 0;
    if (n < k) {
        cout << ans << endl;
        return 0;
    }
    rep(i,n) {
        if (k == 0) break;
        if (0 < s[i]-'0') {
            ans += ll(s[i]-'0'-1) * comb(n-1-i, k-1) * p(9, k-1);
            ans += comb(n-1-i, k) * p(9, k);
            k--;
        }
    }
    if (k == 0) ans++;
    
    cout << ans << endl;
    return 0;
}