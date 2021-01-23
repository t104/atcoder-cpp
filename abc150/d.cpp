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
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void dame() {
    cout << 0 << endl;
    exit(0);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll p = 1;
    ll a0 = a[0];
    while (a0%2 == 0) {
        a0 /= 2;
        p *= 2;
    }

    rep(i,n) {
        if (a[i]%p == 0) {
            a[i] /= p;
            if (a[i]%2 == 0) {
                dame();
            }
        }
        else {
            dame();
        }
    }

    m /= p/2;
    ll l = 1;
    rep(i,n) {
        l = lcm(l, a[i]);
    }

    ll ans = m / l;
    if (ans%2 == 1) ans++;
    ans /= 2;
    cout << ans << endl;
    return 0;
}