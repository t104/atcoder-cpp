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
using P = pair<ll,ll>;

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    int zero = 0;
    map<P,P> mp;
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            zero++;
            continue;
        }
        ll g = gcd(x,y);
        x /= g;
        y /= g;
        // y < 0 のときは 180度回転
        if (y < 0) x = -x, y = -y;
        if (y == 0 && x < 0) x = -x, y = -y;
        bool rot90 = x <= 0;
        if (rot90) {
            ll tmp = x;
            x = y; y = -tmp;
        }
        if (rot90) mp[{x,y}].first++;
        else mp[{x,y}].second++;
    }

    mint ans = 1;
    for (auto p: mp) {
        int s = p.second.first;
        int t = p.second.second;
        mint now = 1;
        now += mint(2).pow(s) - 1;
        now += mint(2).pow(t) - 1;
        ans *= now;
        cout << now.val() << endl;
    }
    ans -= 1;
    ans += zero;
    cout << ans.val() << endl;
    return 0;
}