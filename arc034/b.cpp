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

ll f(ll x) {
    ll res = 0;
    while (0 < x) {
        res += x%10;
        x /= 10;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ni = n;

    int d = 0, r = 0;
    while (ni) {
        d++;
        r = ni;
        ni /= 10;
    }

    rep(i,d) r += 9;
    vector<ll> ans;
    for (ll nj = n-r-1; nj <= n; ++nj) {
        if (nj + f(nj) == n) ans.push_back(nj);
    }

    cout << ans.size() << endl;
    for (auto a: ans) cout << a << endl;
    return 0;
}