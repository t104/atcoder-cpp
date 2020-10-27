#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<ll,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);
    vector<P> sum(n);
    rep(i,n) sum.at(i) = {a.at(i) + b.at(i), i};
    sort(sum.rbegin(), sum.rend());
    ll ans = 0;
    for (int i = 0; i < n; i+=2) ans += a.at(sum.at(i).second);
    for (int i = 1; i < n; i+=2) ans -= b.at(sum.at(i).second);
    cout << ans << endl;
    return 0;
}