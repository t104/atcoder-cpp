#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

const int max_p = 62;

int main() {
    int n;
    cin >> n;
    vector<mint> one(max_p), zero(max_p);
    rep(i,n) {
        ll a;
        cin >> a;
        rep(j,max_p) {
            ((a>>j)&1 ? one.at(j) : zero.at(j)) += 1;
        }
    }

    mint ans = 0;
    rep(i,max_p) {
        ans += one.at(i) * zero.at(i) * (1LL << i);
    }
    cout << ans.val() << endl;
    return 0;
}