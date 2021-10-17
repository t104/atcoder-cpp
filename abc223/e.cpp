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

ll calc(ll s, ll x) {
    ll r = s%x;
    ll q = s / x;
    if (0 < r) q++;
    return q;
}

int main() {
    ll h, w;
    vector<ll> s(3);
    cin >> h >> w;
    rep(i,3) cin >> s[i];
    sort(s.begin(), s.end());
    bool ok = false;
    do {
        rep(i, 2) {
            ll wi = w - calc(s[0], h);
            if (0 < wi) {
                ll wii = wi - calc(s[1], h);
                if (s[2] <= wii * h) {
                    ok = true;
                }
                ll hii = h - calc(s[1], wi);
                if (s[2] <= hii * wi) {
                    ok = true;
                }
            }
            swap(h, w);
        }
    } while (next_permutation(s.begin(), s.end()));

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
