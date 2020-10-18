#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const ll LINF = 1e15;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) a.at(i) -= i+1;
    sort(a.begin(), a.end());
    ll sum = 0;
    rep(i,n) sum += a.at(i);
    ll ans = LINF;
    for (int i = 0; i <= 1; ++i) {
        ll s = 0;
        int ind = min(n-1, n/2 + i);
        rep(j,n) s += abs(a.at(j) - a.at(ind));
        chmin(ans, s);
    }
    cout << ans << endl;
    return 0;
}