#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);
    ll ans = 0;
    rep(i,n) {
        ans += (a.at(i) + b.at(i)) * (b.at(i) - a.at(i) + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}