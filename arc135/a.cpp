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

int main() {
    ll n;
    cin >> n;
    mint ans = 1;
    map<ll, ll> mp, tmp;
    mp[n] = 1;
    bool ok = true;
    while (ok) {
        ok = false;
        for (auto [x, p]: mp) {
            if (x <= 4) {
                ans *= mint(x).pow(p);
                continue;
            }
            ll y1 = x/2LL;
            ll y2 = x/2LL + x%2LL;
            tmp[y1] += mp[x];
            tmp[y2] += mp[x];
            ok = true;
        }
        swap(mp, tmp);
        tmp.clear();
    }
    cout << ans.val() << endl;
    return 0;
}

