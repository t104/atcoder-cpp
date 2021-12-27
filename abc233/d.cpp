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
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    vector<ll> s(n+1);
    rep(i,n) {
        s[i+1] = a[i] + s[i];
    }
    map<ll, ll> mp;
    ll ans = 0;
    rep(i,n+1) {
        ll d = s[i] - k;
        if (mp.count(d)) {
            ans += mp.at(d);
        }
        mp[s[i]]++;
    }
    cout << ans << endl;
    return 0;
}

