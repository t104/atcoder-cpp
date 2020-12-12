#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll tot = 0;
    rep(i,n) tot += a.at(i);
    ll ans = LINF, sum = 0;
    int l = 0, r = 0;
    while (r < n) {
        sum += a.at(r);
        chmin(ans, abs(tot-2*sum));
        ++r;
        while (tot < 2*sum) {
            sum -= a.at(l);
            chmin(ans, abs(tot-2*sum));
            ++l;
        }
    }
    cout << ans << endl;
    return 0;
}