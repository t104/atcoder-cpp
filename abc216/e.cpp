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


int main() {
    int n;
    ll k;
    cin >> n >> k;
    priority_queue<ll> que;
    ll tot = 0LL;
    rep(i,n) {
        ll a;
        cin >> a;
        tot += a;
        que.push(a);
    }
    ll ans = 0;
    if (tot <= k) {
        while (que.size()) {
            ll a = que.top(); que.pop();
            ans += (a+1) * a / 2LL;
        }
        cout << ans << endl;
        return 0;
    }

    ll count = 1;
    while (que.size() && 0 < k) {
        ll mx = que.top(); que.pop();
        if (que.empty()) {
            ll q = k / count;
            ll r = k % count;
            ans += count * (mx + mx-q+1LL) * q / 2LL;
            mx -= q;
            ans += mx * r;
            k = 0;
            break;
        }
        ll second = que.top();
        if (k < (mx-second) * count) {
            while (count < k) {
                ans += mx * count;
                mx--;
                k -= count;
            }
            ans += mx * k;
            k = 0;
        } else {
            ans += count * (mx + second+1LL) * (mx - second) / 2LL;
            k -= count * (mx - second);
            count++;
        }
    }
    cout << ans << endl;
    return 0;
}