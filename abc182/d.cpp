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
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    vector<ll> sum(n);
    sum.at(0) = a.at(0);
    for (int i = 1; i < n; ++i) {
        sum.at(i) = sum.at(i-1) + a.at(i);
    }
    vector<ll> ssum(n), max_sum(n);
    ssum.at(0) = sum.at(0);
    max_sum.at(0) = sum.at(0);
    for (int i = 1; i < n; ++i) {
        ssum.at(i) = ssum.at(i-1) + sum.at(i);
        max_sum.at(i) = max(max_sum.at(i-1), sum.at(i));
    }
    ll ans = max(0LL, ssum.at(n-1));
    rep(i,n-1) {
        chmax(ans, ssum.at(i) + max_sum.at(i));
    }
    cout << ans << endl;
    return 0;
}