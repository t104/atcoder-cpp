#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint998244353;

ll comb(int n, int r) {
    if (r == 0 || r == n) return 1;
    else if (r == 1) return n;
    return comb(n-1, r-1) + comb(n-1, r);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<mint> c;
    rep(i, k+1) c.push_back((mint) comb(k, i));
    for (int i = 1; i < k+1; ++i) c.at(i) += c.at(i-1);
    for (int ki = 1; ki <= k; ++ki) {
        mint ans = (mint) 0;
        rep(i,n) {
            for (int j = i+1; j < n; ++j) {
                mint al = a.at(i);
                mint ar = a.at(j);
                ans += c.at(ki) * al.pow(k-ki) * ar.pow(k);
            }
        }
        cout << ans.val() << endl;
    }
    return 0;
}